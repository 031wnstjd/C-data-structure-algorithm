#include <iostream>

#define MAX_N (100000)
#define MAX_TREE (MAX_N * 4)

using namespace std;

struct DATA {
	int id;
	int cnt;
};

int N;
int need[MAX_N + 10];
DATA tree[MAX_TREE];
int lazy[MAX_TREE];

void Input_Data(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> need[i];
	}
}

inline DATA& max(DATA &a, DATA &b) {
	return a.cnt >= b.cnt ? a : b;
}

void Build_Tree(int node, int s, int e) {
	int m;
	lazy[node] = 0;
	if (s == e) {
		tree[node].id = s;
		tree[node].cnt = 0;
		return;
	}
	m = (s + e) / 2;
	Build_Tree(node * 2, s, m);
	Build_Tree(node * 2 + 1, m + 1, e);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void Propagate(int node, int s, int e) {
	if (lazy[node]) {
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node].cnt += lazy[node];
		lazy[node] = 0;
	}
}

void Update(int node, int s, int e, int qs, int qe) {
	Propagate(node, s, e);

	if (e < qs || qe < s) return;
	if (qs <= s && e <= qe) {
		lazy[node] += 1;
		Propagate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	Update(node * 2, s, m , qs, qe);
	Update(node * 2 + 1, m + 1, e, qs, qe);
	
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int Solve(void) {
	for (int i = 1; i <= N; i++) {
		if (need[i] >= N) continue;
		if (need[i] == 0) {
			Update(1, 1, N, 1, N); // 전체 구간 업데이트
		}
		else {
			int qs = i % N + 1; // cnt 증가 구간 시작 지점
			int qe = (i - 1 - need[i] + N) % N + 1; // cnt 증가 구간 끝 지점

			if (qs <= qe) Update(1, 1, N, qs, qe);
			else {
				Update(1, 1, N, qs, N);
				Update(1, 1, N, 1, qe);
			}
		}
	}
	return tree[1].id; // 루트 노드(cnt값 최대)의 id 값 출력
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	Build_Tree(1, 1, N);

	cout << Solve() << '\n';

	return 0;
}

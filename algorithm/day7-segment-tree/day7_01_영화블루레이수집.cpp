/*
	백준 3653 영화수집
*/
#include <iostream>

#define MAX_N (100000)
#define MAX_M (100000)
#define MAX_TREE (MAX_N * 8)

using namespace std;

int T;
int N, M;

int tree[MAX_TREE];
int pos[MAX_N + MAX_M];

void Build_Tree(int node, int s, int e) {
	if (s == e) {
		tree[node] = s > M ? 1 : 0; // 1 ~ M 구간 값은 0 (비어 있음), M+1 ~ M+N 구간 값은 1 (영화 존재)
		return;
	}

	int m = (s + e) / 2;
	Build_Tree(node * 2, s, m);
	Build_Tree(node * 2 + 1, m + 1, e);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int s, int e, int qs, int qe) {
	if (qs <= s && e <= qe) return tree[node];
	if (e < qs || qe < s) return 0;
	int m = (s + e) / 2;
	int l = Query(node * 2, s, m, qs, qe);
	int r = Query(node * 2 + 1, m + 1, e, qs, qe);
	return l + r;
}

void Update(int node, int s, int e, int idx, int data) {
	if (s == e) {
		tree[node] = data;
		return;
	}

	int m = (s + e) / 2;
	if (idx <= m) Update(node * 2, s, m, idx, data);
	else  Update(node * 2 + 1, m + 1, e, idx, data);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void Init(void) {
	Build_Tree(1, 1, M + N);
	for (int i = 1; i <= N; i++) {
		pos[i] = M + i;
	}
}

void Search_And_Move_Bluray() {
	for (int newpos = M; newpos >= 1; newpos--) {
		int target;
		cin >> target;
		int ans = Query(1, 1, M + N, 1, pos[target] - 1); // target 바로 위까지 영화 개수의 합
		cout << ans << " ";
		Update(1, 1, M + N, pos[target], 0); // 원래 있던 곳의 값 0으로
		pos[target] = newpos;
		Update(1, 1, M + N, pos[target], 1); // 새로 위치한 곳의 값 1로
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N >> M;
		Init();
		Search_And_Move_Bluray();
	}

	return 0;
}

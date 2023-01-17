/*
	백준 1395 스위치
*/

#include <iostream>

using namespace std;

#define MAX_N (100000)
#define MAX_M (100000)
#define MAX_TREE (MAX_N * 4)

int N, M;
int O, S, T;

int tree[MAX_TREE]; // 0 : 꺼짐, 1 : 켜짐
int lazy[MAX_TREE]; // 0 : 반전 X, 1 : 반전 O

void Propagate(int node, int s, int e) {
	if (lazy[node]) {
		if (s != e) { // 리프노드가 아니라면(자식이 있다면) 전파
			lazy[node * 2] = !lazy[node * 2]; // 기존에 0이었으면 1로, 1이었으면 0으로
			lazy[node * 2 + 1] = !lazy[node * 2 + 1]; // 기존에 0이었으면 1로, 1이었으면 0으로
		}
		tree[node] = (e - s + 1) - tree[node]; // 해당 구간의 스위치 개수 - (반전 하기 전에 해당 구간에 켜져 있던 스위치 개수)
		lazy[node] = 0;
	}
}

void Update(int node, int s, int e, int us, int ue) {
	Propagate(node, s, e);

	if (e < us || ue < s) return;
	if (us <= s && e <= ue) {
		lazy[node] = 1; // 업데이트 해야됨을 기록
		Propagate(node, s, e);
		return;
	}

	int m = (s + e) / 2;
	Update(node * 2, s, m, us, ue);
	Update(node * 2 + 1, m + 1, e, us, ue);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int Query(int node, int s, int e, int qs, int qe) {
	Propagate(node, s, e);

	if (qs <= s && e <= qe) return tree[node];
	if (e < qs || qe < s) return 0;

	int m = (s + e) / 2;
	int l = Query(node * 2, s, m, qs, qe);
	int r = Query(node * 2 + 1, m + 1, e, qs, qe);

	return l + r;
}

void Solve(int o, int s, int e) {
	if (o == 0) { // s ~ e 스위치 상태 반전
		Update(1, 0, N, s, e);
	}
	else { // s ~ e 스위치 개수 출력
		int ret = Query(1, 0, N, s, e);
		cout << ret << '\n';
	}
}

void Input_Data(void) {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> O >> S >> T;
		Solve(O, S, T);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	return 0;
}

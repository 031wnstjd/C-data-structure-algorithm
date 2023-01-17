/*
    백준 12015 가장 긴 증가하는 부분 수열 2

	[문제유형]
	- LIS(Longest Increasing Sequence, 최장 증가 부분 수열) 문제
	
	[아이디어]
	- max_len[i] : i번째 원소까지 고려했을 때 LIS 길이

	[풀이방법]
	- Dynamic Programming 풀이 시간복잡도 : O(N^2)
	- Segment Tree 풀이 시간복잡도 : O(NlogN)
*/

#include <iostream>
#include <algorithm>

#define MAX_N (1000000)
#define MAX_TREE (1000000)

using namespace std;

int N;
int max_num;
int nums[MAX_N+10];
int tree[MAX_TREE * 4];

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
		if (max_num < nums[i]) max_num = nums[i]; // 구간 끝 부분
	}
}

int Query(int node, int s, int e, int qs, int qe) {
	if (qs <= s && e <= qe) return tree[node];
	if (e < qs || qe < s) return 0;

	int m = (s + e) / 2;
	int l = Query(node * 2, s, m, qs, qe);
	int r = Query(node * 2 + 1, m + 1, e, qs, qe);

	return max(l, r);
}

void Update(int node, int s, int e, int idx, int len) {
	if (s == e) {
		tree[node] = len;
		return;
	}
	int m = (s + e) / 2;
	if (idx <= m) Update(node * 2, s, m, idx, len);
	else Update(node * 2 + 1, m + 1, e, idx, len);

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]); // 구간 내 최댓값 저장
}



int Solve() {
	int i;
	int len;

	for (int i = 0; i < N; i++) {
		len = Query(1, 0, max_num, 0, nums[i] - 1) + 1;
		Update(1, 0, max_num, nums[i], len);
	}

	return tree[1]; // 최장 증가 부분 수열 길이 리턴
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input_Data();

	cout << Solve() << '\n';

	return 0;
}

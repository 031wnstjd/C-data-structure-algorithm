/*
	[Rule]
	- 원소를 넣고 나면 항상 왼쪽(내림차순 pq)이 사이즈가 1 더 큼
	- 항상 왼쪽 pq에서 median을 읽음
*/
#include <iostream>
#include <queue>

using namespace std;

int N, P, Q;

struct COMP{
	bool operator()(int a, int b) {
		return a > b; // 작을수록 우선순위 높음
	}
};

priority_queue<int, vector<int>> pq_small; // 크면 클수록 우선순위 높음 (왼쪽 pq)
priority_queue<int, vector<int>, COMP> pq_big; // 작으면 작을수록 우선순위 높음 (오른쪽 pq)

int Get_Median(void) {
	return pq_small.top();
}

void Put_Element(int e) {
	if (pq_small.empty() || pq_small.top() > e) { // pq_small이 비었거나, pq_small 내 최댓값보다 더 작다면
		pq_small.push(e);
		if (pq_small.size() > pq_big.size() + 1) {
			pq_big.push(pq_small.top());
			pq_small.pop();
		}
	}
	else {
		pq_big.push(e);
		if (pq_big.size() > pq_small.size()) {
			pq_small.push(pq_big.top());
			pq_big.pop();
		}
	}
}

void Solve(void) {
	cin >> N;
	int init;
	cin >> init;
	Put_Element(init);
	cout << Get_Median() << '\n';
	N /= 2;
	for (int i = 0; i < N; i++) {
		cin >> P >> Q;
		Put_Element(P);
		Put_Element(Q);
		cout << Get_Median() << '\n';
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	Solve();
	
	return 0;
}

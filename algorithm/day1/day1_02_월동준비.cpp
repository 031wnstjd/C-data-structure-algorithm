#include <iostream>

using namespace std;

#define MAX_N (50000)
#define MAX_Q (200000)

struct QUESTION {
	int s, e, a;
};

int N, Q;
int D[MAX_N + 1];
QUESTION q[MAX_Q];

void Input_Data(void) {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
	}
	for (int i = 0; i < Q; i++) {
		cin >> q[i].s >> q[i].e;
	}

}

void Print_Result(void) {
	for (int i = 0; i < Q; i++) {
		cout << q[i].a << '\n';
	}
}

void Solve() {
	// Prefix-sum 테이블 생성 : O(N)
	for (int i = 2; i <= N; i++) {
		D[i] += D[i - 1];
	}

	// 질문의 답 생성
	for (int i = 0; i < Q; i++) {
		q[i].a = D[q[i].e] - D[q[i].s - 1];
	}
}




int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);

	Input_Data();

	Solve();

	Print_Result();
	   	 
	return 0;
}

/**
	백준 3078 좋은친구 
*/

#include <iostream>
#include <string>

using namespace std;

#define MAX_N (300000)
#define MAX_K (K)
#define MAX_LEN (20)

int N, K;
int len[MAX_N]; // 이름 길이 배열 
int cnt_len[MAX_LEN+1]; // 구간 내 이름 길이에따른 원소 개수 카운트 

void Input_Data(void) {
	string s; 
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> s;
		len[i] = s.length();
	}
}

long long Solve() {
	long long sol = 0;
	for (int e = 0; e <= K; e++) { // 처음 K번째까지는 더하기만  
		sol += cnt_len[len[e]];
		cnt_len[len[e]]++;
	}
	for (int e = K+1; e < N; e++) {
		cnt_len[len[e - K - 1]]--; // 윈도우에서 삭제되는 놈의 cnt 값을 1 줄임 
		sol += cnt_len[len[e]];
		cnt_len[len[e]]++; // 윈도우에서 추가되는 놈의 cnt 값을 1 늘림 
	}
	return sol;
}


int main(void) {
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);

	// 입력 받는 부분
	Input_Data();

	// 출력하는 부분
	cout << Solve() << '\n';

	return 0;
}

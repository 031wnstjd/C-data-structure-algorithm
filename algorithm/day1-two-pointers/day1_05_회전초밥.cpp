#include <iostream>
using namespace std;

#define MAX_N (3000000)
#define MAX_K (3000)
#define MAX_D (3000)

int N; // 접시의 수 
int D; // 초밥 가짓수 
int K; // 연속해서 먹는 접시의 수  
int C; // 쿠폰 번호 

int sushi[MAX_N];
int cnt_sushi[MAX_D+1]; // 구간 내 특정 초밥의 개수 

void InputData() {
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
}

int Solve() {
	
	int max_cnt; 
	int cnt = 1; // 초밥 가짓수 1로 초기화 
	cnt_sushi[C]++; // 쿠폰 번호에 해당하는 초밥 개수 카운트 (선반영) 
		
	// 1. INITIAL CONDITION (i == 0)
	for (int i = 0; i < K; i++) {
		if(cnt_sushi[sushi[i]] == 0) cnt++;
		cnt_sushi[sushi[i]]++;
	} 
	
	max_cnt = cnt;
	
	// 2. SLIDING WINDOW (0 < i < N)
	for (int i = 1; i < N; i++) { 
		int before_idx = i - 1 < 0 ? N - 1 : i - 1; 
		cnt_sushi[sushi[before_idx]]--; // 맨 앞 원소 삭제
		if(cnt_sushi[sushi[before_idx]] == 0) cnt--; // 가짓수 감소 
		
		int new_idx = (i + K - 1) % N;
		if(cnt_sushi[sushi[new_idx]] == 0) cnt++; // 가짓수 증가 
		cnt_sushi[sushi[new_idx]]++; // 맨 뒤 원소 추가
		
		if(max_cnt < cnt) max_cnt = cnt;
	}
		
	return max_cnt;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 	
	InputData();
 	
 	cout << Solve() << '\n'; 
 
    return 0;
}

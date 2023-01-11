#include <iostream>

#define MAX_N (100000)

using namespace std;

/**
	[아이디어]
	입양될 수 있는 '최대 아이들의 수'를 구하기 위해
	특정 아이들의 수를 기준으로 모든 마을에 대해 비용을 따졌을 때
	입양이 가능한지를 판단
	=> 특정 아이들의 수를 이진 탐색으로 결정 
*/

int N;

struct TOWN {
	int pos; // 도시 위치 
	int fish; // 물고기 양 
};

TOWN towns[MAX_N + 10];

int min_fish = 1000000001;
int max_fish = -1;

void Input_Data(void) {
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> towns[i].pos >> towns[i].fish;	
		if(towns[i].fish < min_fish) min_fish = towns[i].fish; // 최소 물고기 수 
		if(towns[i].fish > max_fish) max_fish = towns[i].fish; // 최대 물고기 수 
	}
}

bool Check(int child) {
	long long cost = 0;
	long long remain; 
	for(int i = 0; i < N; i++) {
		remain = towns[i].fish + cost - child; // i번째 도시가 갖고 있는 물고기 양에서 이전에 누적된 cost를 더하고, 입양아 수를 뺌 
		cost = remain - (towns[i + 1].pos - towns[i].pos);
		if(remain >= 0 && cost < 0) cost = 0; // 남은 물고기 양은 0보다 크거나 같은데 다음 도시와의 거리가 이보다 더 크면 cost = 0으로 초기화 (물고기 이동 불가)
	}
	return remain >= 0; // 마지막(N-1번째) 마을에서 남은 물고기의 양이 0보다 크거나 같으면 true, 아니면 false를 리턴 
}

int Solve(void) {
	int s = min_fish;
	int e = max_fish;
	
	int ans = -1;
		
	while(s <= e) {
		int m = (s + e) / 2; // 초기에 가정할 수 있는 최대 입양아 수 = (최대 물고기 양 + 최소 물고기 양) / 2 
		if(Check(m)) { // m명이 입양 가능하다면, m보다 큰 영역에서 다시 판단하기 위해 s = m + 1 
			s = m + 1;
			ans = m;  
		}
		else e = m - 1;
	}
	
	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input_Data();
	
	cout << Solve() << '\n';
			
	return 0;
}

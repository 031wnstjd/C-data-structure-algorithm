#include <iostream>
#include <algorithm>

#define MAX_M (100000)
#define MAX_N (100000)

using namespace std;
/**
	[아이디어]
	동물 입장에서 잡힐 수 있는 사냥꾼이 한 명이라도 존재하면 됨
	=> 이진탐색 ('구간의 경계값'을 구해야 하거나 '구간 내에 특정 수가 포함되는지 판별'하는 문제는 이진탐색 고려. 단, '정렬된 배열'이어야 함) 
	=> O(NlogM) 
*/

int M; // 사대의 수 
int N; // 동물의 수
int L; // 사정거리 

struct POS {
	int x, y;
};

int hunters[MAX_M];
POS animals[MAX_N];

void Input_Data(void) {
	cin >> M >> N >> L;
	for(int i=0; i<M; i++) {
		cin >> hunters[i];
	}
	for(int i=0; i<N; i++) {
		cin >> animals[i].x >> animals[i].y;
	}	
}

int Binary_Search_Lower(int s, int e, int d) {
	int m;
	int sol = -1;
	
	while(s <= e) {
		m = (s + e) / 2;
		if(hunters[m] >= d) { // d보다 큰 것 중에 가장 작은 거 
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	
	return sol;
}

int Solve(void) {
	int cnt = 0;
	
	sort(hunters, hunters + M); // 사대 오름차순 정렬 
	
	for(int i = 0; i < N; i++) {
		if(animals[i].y > L) continue;
		int l = animals[i].x - (L - animals[i].y);
		int r = animals[i].x + (L - animals[i].y);
		
		int lower = Binary_Search_Lower(0, M - 1, l);
		
		if(lower != -1 && hunters[lower] <= r) cnt++; // lower가 존트재하고, 해당 위치가 r보다 작거나 같다면 카운 
	}
	
	return cnt;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input_Data();
	
	cout << Solve() << '\n';
	
	return 0;
}

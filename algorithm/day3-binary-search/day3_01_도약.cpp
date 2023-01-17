#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N (1000)

int N;
int pos[MAX_N+10];

void Input_Data(void) {
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> pos[i];
	}
}

int Binary_Search_Lower(int s, int e, int d) {
	int m;
	int sol = -1;
	
	while(s <= e) {
		m = (s + e) / 2;
		if(pos[m] >= d) {
			sol = m;
			e = m - 1;
		}
		else s = m + 1;
	}
	
	return sol;	
}

int Binary_Search_Upper(int s, int e, int d) {
	int m;
	int sol = -1;
	
	while(s <= e) {
		m = (s + e) / 2;
		if(pos[m] <= d) {
			sol = m;
			s = m + 1;
		}
		else e = m - 1;
	}
	
	return sol;	
}

int Solve(void) {
	sort(pos, pos+N); // 연잎 좌표 오름차순 정렬 
	
	int cnt = 0;
	for(int s1 = 0; s1 < N - 2; s1++) {  // 첫 번째 연잎 index 선택
		for(int s2 = s1 + 1; s2 < N - 1; s2++) { // 두 번째 연잎 index 선택 
			int dist = pos[s2] - pos[s1];
			int l = pos[s2] + dist; // 도약해야하는 최소 위치 
			int r = pos[s2] + dist * 2; // 도약해야하는 최대 위치 
			
			int lower_bound = Binary_Search_Lower(s2 + 1, N - 1, l);
			 
			if(lower_bound != -1 && pos[lower_bound] <= r) { // lower_bound가 존재하고, r(도약 최대 위치)보다는 작거나 같다면 
				int upper_bound = Binary_Search_Upper(s2 + 1, N - 1, r); // lower_bound가 존재하면 upper_bound는 무조건 존재
				cnt += (upper_bound - lower_bound + 1); 
			}
		}
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

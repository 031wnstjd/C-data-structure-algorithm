#include <iostream>

using namespace std;

#define MAX_N (100000)

struct STUDENT {
	int pos, vel;
};

int N;
STUDENT students[MAX_N];

void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++ ) {
		cin >> students[i].pos >> students[i].vel;
	}
}

int Solve(void) {
	int cnt = 0;
	int min_vel = 1000000001;
	
	for (int i = N-1; i >= 0; i--) {
		min_vel = students[i].vel < min_vel ? students[i].vel : min_vel;
		if(students[i].vel - min_vel <= 0) cnt++;
	}
	
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	Input_Data();
	
	cout << Solve() << '\n';
	
}

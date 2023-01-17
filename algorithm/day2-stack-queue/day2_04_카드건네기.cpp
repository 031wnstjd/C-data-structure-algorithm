#include <iostream>
#include <deque>
using namespace std;

#define MAX_N (100)

int N;
deque<int> que;

void Input_Data(void) {
	cin >> N;
	for (int i=1; i<=N; i++) {
		que.push_back(i);
	}
}

void Solve(void) {
	for(int i=0; i<N; i++) {
		int mod = que.back() / 2;
		for(int j=0; j<mod; j++) {
			int tmp = que.front();
			que.pop_front();
			que.push_back(tmp);
		}
		cout << que.front() << " ";
		que.pop_front(); 
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input_Data();
	
	Solve();
	
}

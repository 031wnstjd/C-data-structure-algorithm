#include <iostream>
#include <deque>

using namespace std;

#define MAX_N (80000)
#define MAX_H (1000000000)

int N;
int h[MAX_N];
int cnt[MAX_N]; // i번째 소를 볼 수 있는 소들의 수 카운트 
deque<int> stack;


void Input_Data(void) {
	
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> h[i];
	} 
	
}

int Solve(void) {
	for (int i=0; i<N; i++) {
		while (!stack.empty()) { // stack이 비어있지 않다면 
			if(stack.back() > h[i]) { 
				cnt[i] += stack.size();		 
				break;
			}
			else {
				stack.pop_back();
			}
		}		
		stack.push_back(h[i]);
	}
}

void Print_Result(void) {
	long long sum = 0;
	for(int i=0; i<N; i++) {
		sum += cnt[i];
	}
	cout << sum << '\n';
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input_Data();
	
	Solve();
	
	Print_Result();	
	
	return 0;
} 

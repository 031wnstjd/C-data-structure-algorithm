#include <iostream>
#include <deque>
#include <string>

using namespace std;

#define MAX_N (500000)

int N, K;
string num; // 500,000 자리 수 이므로 int로 받지 않고 string으로 받음 
deque<char> stk; // 문자를 저장하는 deque 선언 

void Input_Data(void) {
	cin >> N >> K;
	cin >> num;
}

void Solve(void) {
	stk.clear(); // 초기화
	for (char n : num) {
		while (!stk.empty() && K && stk.back() < n) { // K : 지울 수 있는 숫자가 남아 있을 때 
			stk.pop_back();
			K--; // 지울 수 있는 숫자 개수 1 감소 
		}
		stk.push_back(n);
	}
	for (int i=0; i<K; i++) stk.pop_back();  
}

void Print_Result(void) {
	for (char n : stk){
		cout << n;
	}
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

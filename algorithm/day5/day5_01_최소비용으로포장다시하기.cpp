#include <iostream>
#include <queue>

/**
	시간복잡도 : NlogN 
*/

using namespace std;

#define MAX_N (5000)
#define MAX_NI (100)

int N;
int d[MAX_N];

struct COMP {
	bool operator() (int a, int b) {
		return a > b;
	}
};

priority_queue<int, vector<int>, COMP> pq;

void Input_Data(void) {
	pq = priority_queue<int, vector<int>, COMP>(); // pq 초기화  
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		pq.push(d[i]);
	}
}

int Solve(void) { 
	int cost = 0;

	while(!pq.empty()) {		
		int num1 = pq.top();		
		pq.pop(); 
		if(!pq.empty()) { // pq가 비어있지 않다면  
			int num2 = pq.top();
			pq.pop();
			cost += (num1 + num2);
			pq.push(num1 + num2);	 
		}
	}
	
	return cost;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	Input_Data();
	
	cout << Solve() << '\n';
	
}

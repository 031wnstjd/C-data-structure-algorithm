#include <iostream>
#include <deque>
using namespace std;

#define MAX_N (100000)

long long N;//히스토그램수
long long H[MAX_N+10];//히스토그램 높이

deque<int> stack; // 히스토그램의 idx를 담음 

bool InputData() {
    cin >> N;
    if (N == 0) return false;
    
    for (int i=0; i<N; i++){
        cin >> H[i];
    }
    H[N] = -1; // 마지막 위치에 있는 히스토그램 계산을 위함  
     
	return true;
}
 
long long Solve() { 
	long long res = 0;
	stack.clear();
	
	for (int i=0; i<=N; i++) { // 마지막 히스토그램 계산을 위해 i = N 까지 
		while(!stack.empty() && H[stack.back()] > H[i]) { // 새로 들어오는 놈의 높이가 더 작으면 이전까지의 넓이들을 계산 
			int width, h_idx;
			
			h_idx = stack.back();
			stack.pop_back();
			
			if(stack.empty()) width = i; 
			else width = i - stack.back() - 1; // i - h_idx로 하면 안 됨 
			
			res = H[h_idx] * width > res ? H[h_idx] * width : res; // 넓이 최댓값 갱신  
		}
		
		stack.push_back(i); // stack.empty() || stack.back() <= H[i]
	}
	
	return res; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);
		
    while(InputData()){//입력받는 부분
        cout << Solve() << "\n";//출력하는 부분
    }
    return 0;
}

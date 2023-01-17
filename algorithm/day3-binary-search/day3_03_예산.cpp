#include <iostream>
#include <algorithm>

/**용 
	[아이디어]
	정렬된 구간 내에서 특정 숫자를 
	시간복잡도 O(logN)이하로 찾으려면
 	"이진탐색" 활 
*/
using namespace std;

#define MAX_N (10000)
#define MAX_M (1000000000)

int N; // 지방의 수
int M; // 총 예산 
long long sum;
int budget[MAX_N];

void Input_Data(void) {
	sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		sum += budget[i];
	}
	cin >> M;
}

bool Check(int limit) { // O(N)
	long long tmp = 0;
	for (int i = 0; i < N; i++) {
		if(budget[i] < limit) tmp += budget[i];
		else tmp += limit;
	}
	if(tmp > M) return false;
	return true;
}

int Set_Limit(int s_val, int e_val) { // O(NlogN)
	int limit = -1; // 최소 상한액 
	int m_val;
	 
	while(s_val <= e_val) {
		m_val = (s_val + e_val) / 2; // O(logN)
			
		if(Check(m_val)) { // 상한액이 더 커지는 게 가능하면 업데이트  
			s_val = m_val + 1;
			limit = m_val;
		}
		else e_val = m_val - 1; // 상한액이 더 커지는 게 불가능하면 상한액 줄이기 
	}

	return limit;
}

int Solve(void) { 
	sort(budget, budget + N); // 예산 요청 금액 오름차순 정렬
	
	if(sum <= M) return budget[N - 1]; // 모두 다 배정될 수 있으면, 기존 예산의 최댓값 반환 

	// 모두 배정될 수 없으면, 최대 상한액 정해서 반환 
	return Set_Limit(0, budget[N - 1]); // 최소값을 budget[0]이 아닌 0으로 해야함 (배정 예산이 budget[0]보다 작은 상황도 존재하므로) 
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Input_Data();
	
	cout << Solve() << '\n';	
	
	return 0;
} 

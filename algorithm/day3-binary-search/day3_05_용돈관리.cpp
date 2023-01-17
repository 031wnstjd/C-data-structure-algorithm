#include <iostream>
using namespace std;
 
#define MAX_N (100000)
 
int N, M;
int sum = 0;
int max_cost = -1;
int cost[MAX_N + 10];
 
void Input_Data(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        if(cost[i] > max_cost) max_cost = cost[i];
        sum += cost[i];
    }
}
 
bool Check(int K) {
    int cnt_M = M - 1; // 처음에 K원 인출해야 하므로 M-1로 초기화 
    int tmp = K; // 계산 결과 값 임시 저장 
    for (int i = 1; i <= N; i++) {
        if(tmp - cost[i] < 0) { // 계산 결과가 음수면 
            cnt_M--; // 인출 횟수 감소 
            tmp = K - cost[i]; // 인출 
        } 
        else tmp = tmp - cost[i];
         
        if(cnt_M < 0) return false; // 인출 횟수 초과시 false 리턴 
    }
     
    return true;
}
 
int Solve(void) {
    int K;
     
    int s = max_cost;
    int e = sum;
     
    while(s <= e) {
        int m = (s + e) / 2;
        if(Check(m)) { // 만약 K값으로 m이 가능하다면 더 작은 값 찾기 
            K = m;
            e = m - 1;
        }   
        else s = m + 1; // 불가능 하다면 더 큰 값 찾기 
    }
         
    return K;   
}
  
int main(void)
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Input_Data();
  
    cout << Solve() << '\n';
  
    return 0;
}

/**
  백준 5896 효율적으로 소 
*/

#include <iostream>
#include <queue>
 
using namespace std;
 
#define MAX_N (50000)
 
struct PROD {
    int id;
    int P;
    int C;
    bool sold;
};
 
int N, K;
long long M;
PROD prod[MAX_N];
 
struct COMP_P {
    bool operator( )(PROD* a, PROD* b) {
        return a->P > b->P;
    }
};
 
struct COMP_C {
    bool operator()(PROD* a, PROD* b) {
        return a->C > b->C;
    }
};
 
struct COMP_DIFF {
    bool operator()(int a, int b) {
        return a > b;
    }
};
 
priority_queue<PROD*, vector<PROD*>, COMP_P> pq_P;
priority_queue<PROD*, vector<PROD*>, COMP_C> pq_C;
priority_queue<int, vector<int>, COMP_DIFF> pq_benefit;
 
void Input_Data(void) {
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        cin >> prod[i].P >> prod[i].C;
        prod[i].id = i;
        pq_P.push(&prod[i]);
        pq_C.push(&prod[i]);
    }
}
 
int Solve(void) {
    int cnt = 0;
    for (int k = 0; k < K; k++) {
        pq_benefit.push(0);
    }
 
    while (M > 0) {
        while (!pq_P.empty() && pq_P.top()->sold) pq_P.pop();
        PROD* prod_P = pq_P.empty() ? (PROD*)0 : pq_P.top();
 
        while (!pq_C.empty() && pq_C.top()->sold) pq_C.pop();
        PROD* prod_C = pq_C.empty() ? (PROD*)0 : pq_C.top();
        int benefit = pq_benefit.top();
 
        if ((prod_P == (PROD*)0) && (prod_C == (PROD*)0)) break;
        if (prod_P->P <= prod_C->C + benefit) {
            M -= prod_P->P;
            if (M < 0) break;
            prod_P->sold = true;
            pq_P.pop();
            cnt++;
        }
        else {
            M -= prod_C->C + benefit;
            if (M < 0) break;
            pq_benefit.pop();
            pq_benefit.push(prod_C->P - prod_C->C);
            prod_C->sold = true;
            pq_C.pop();
            cnt++;
        }
    }
    return cnt;
}
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    Input_Data();
 
    cout << Solve() << '\n';
 
    return 0;
}

#include <stdio.h>
 
#define NUM_DATA    (5) 
#define MAX_DATA    (NUM_DATA)
#define MAX_TREE    (8 * 2) // (NUM_DATA 이상 2의 제곱수 최소값) * 2
#define LAST_NODE   (MAX_TREE - 1)
 
int tree[MAX_TREE];
 
void main(void)
{
 
}

// 작성한 코드를 아래에 넣으시오.
 
int Query(int node,int s,int e,int qs,int qe)
{
    int m;
    // 1. 쿼리 구간 밖에 존재하는 경우
    if (s < qs || e > qe) return 0;
 
    // 2. 쿼리 구간 안에 존재하는 경우
    if (qs <= s && qe <= e) return tree[node];
 
    // 3. 쿼리 구간의 일부만 포함하는 경우
    m = (s + e) / 2;
    return Query(node * 2, s, m, qs, qe) + Query(node * 2 + 1, m + 1, e, qs, qe); // 1, 2에 의해 각 케이스(구간 검증)에 맞게 계산돼서 리턴 값이 올라옴
}

#include <stdio.h>
 
#define NUM_DATA    (5)
#define MAX_DATA    (NUM_DATA)
#define MAX_TREE    (MAX_DATA*2)
#define LAST_NODE   (MAX_DATA*2-1)
 
int tree[MAX_TREE];
int lazy[MAX_TREE];
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
void Propagate(int node,int s,int e)
{
    if (lazy[node]) { // lazy 값이 있으면 propagation 진행
        if (s != e) { // 자식이 존재하는 경우(== 리프노드가 아닌 경우)
            lazy[node * 2] += lazy[node]; // 현재 노드의 lazy 정보를 왼쪽 자식에게 전파(추가)
            lazy[node * 2 + 1] += lazy[node]; // 현재 노드의 lazy 정보를 오른쪽 자식에게 전파(추가)
        }
        tree[node] += lazy[node] * (e - s + 1); // node 예하에 존재하는 데이터들의 개수만큼 lazy 정보를 반영
        lazy[node] = 0; // node의 lazy 정보 초기화
    }
}

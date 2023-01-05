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
 
void Update_New_Data(int node,int s,int e,int idx,int data)
{
    int m;
    if (s == e) { // 리프 노드일 때
        tree[node] = data;
        return;
    }
 
    m = (s + e) / 2;
 
    if (idx <= m) Update_New_Data(node * 2, s, m, idx, data); // s : 구간 시작 인덱스, e : 구간 끝 인덱스, idx : 수정하고자 하는 data 인덱스
    else  Update_New_Data(node * 2 + 1, m + 1, e, idx, data);
 
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 바뀐 자식 데이터 값을 반영해서 구간 합 수정
}

#include <stdio.h>
 
#define NUM_DATA    (5)
#define MAX_DATA    (NUM_DATA)
#define MAX_TREE    (MAX_DATA*2)
#define LAST_NODE   (MAX_DATA*2-1)
 
int tree[MAX_TREE];
int lazy[MAX_TREE];
 
void Propagate(int node,int s,int e)
{
    if(lazy[node]!=0)
    {
        if(s!=e)
        {
            lazy[node*2] += lazy[node];
            if(node*2+1 <= LAST_NODE) lazy[node*2+1] += lazy[node];
        }
        tree[node] += (e-s+1)*lazy[node];
        lazy[node] = 0;
    }
}
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
void Update_New_Data_Lazy(int node,int s,int e,int idx,int data)
{
    int m;
    Propagate(node, s, e); // propagation 진행
 
    if (idx < s || e < idx) return; // 구간을 벗어난 노드의 경우 데이터 업데이트 없이 그냥 리턴
 
    if (s == e) { // 리프노드인 경우
        tree[node] = data;
        return;
    }
     
    m = (s + e) / 2;
 
    /*
        실제로 idx는 왼쪽 자식 또는 오른쪽 자식 둘 중 하나와만 연관되지만 
        tree[node] = tree[node * 2] + tree[node * 2 + 1]를 진행하는 과정에서
        자식들의 데이터를 propagation으로 업데이트 해줘야 하기 때문에 양쪽 자식 모두 재귀호출 진행
    */
 
    Update_New_Data_Lazy(node * 2, s, m, idx, data);
    Update_New_Data_Lazy(node * 2 + 1, m + 1, e, idx, data);
 
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
}

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
 
void Update_Add_Lazy(int node,int s,int e,int us,int ue,int add)
{
    int m;
    Propagate(node, s, e);
 
    if (e < us || ue < s) return;
    if (us <= s && e <= ue) {
        lazy[node] = add; // 위의 Propagate에서 lazy값이 0으로 초기화 됐으므로 add를 그냥대입
        Propagate(node, s, e); // 예하 노드들에게 lazy 정보만 전달
        return;
    }
 
    m = (s + e) / 2;
    Update_Add_Lazy(node * 2, s, m, us, ue, add);
    Update_Add_Lazy(node * 2 + 1, m + 1, e, us, ue, add);
 
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

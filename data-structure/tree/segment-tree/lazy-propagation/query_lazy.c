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
 
int Query_Lazy(int node,int s,int e,int qs,int qe)
{
    int m,l,r;
    Propagate(node, s, e); // propagtion 진행 추가
 
    if (qs <= s && e <= qe) return tree[node];
    if (e < qs || qe < s) return 0;
 
    m = (s + e) / 2;
     
    l = Query_Lazy(node * 2, s, m, qs, qe);
    r = Query_Lazy(node * 2+1, m+1, e, qs, qe);
 
    return l + r;
}

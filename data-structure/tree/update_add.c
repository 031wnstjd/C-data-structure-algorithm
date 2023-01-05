#include <stdio.h>
 
#define NUM_DATA    (5)
#define MAX_DATA    (NUM_DATA)
#define MAX_TREE    (MAX_DATA*2)
#define LAST_NODE   (MAX_DATA*2-1)
 
int tree[MAX_TREE];
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
void Update_Add(int node, int s, int e, int us, int ue, int add)
{
    int m;
    if (e < us || ue < s) return;
    if (s == e) {
        tree[node] += add;
        return;
    }
 
    m = (s + e) / 2;
    Update_Add(node * 2, s, m, us, ue, add);
    Update_Add(node * 2 + 1, m + 1, e, us, ue, add);
 
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

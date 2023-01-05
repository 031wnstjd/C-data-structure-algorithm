#include <stdio.h>
#include <stdlib.h>
 
#define NUM_NODE 6
#define NUM_EDGE 16
 
typedef struct
{
    int s;
    int e;
    int cost;
}EDGE;
EDGE edge[16] = {{1,2,3},{1,4,6},{1,5,12},{2,3,2},{2,4,9},{3,2,4},{3,5,6},{3,6,7},{4,1,8},{4,5,5},{5,2,11},{5,3,8},{5,4,7},{5,6,5},{6,2,13},{6,3,5}};
 
typedef struct list
{
    int node;
    int cost;
    struct list *next;
}LIST;
 
LIST list[NUM_NODE+1];
 
int main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
int Init_Graph_Adjacency_list(void)
{
    int i;
    for (i = 0; i < NUM_EDGE; i++) {
        LIST *newnode = calloc(1, sizeof(LIST));
        if (newnode == (LIST*)0) return 0;
 
        // 1. 새로운 노드 변수 값 할당
        newnode->node = edge[i].e;
        newnode->cost = edge[i].cost;
         
        // 2. 새로운 노드의 연결관계 정의
        newnode->next = list[edge[i].s].next;
        list[edge[i].s].next = newnode;
         
    }
}

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
 
#define NOT_CONNECTED   (0x7fffffff)
int matrix[NUM_NODE+1][NUM_NODE+1];
 
int main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
void Init_Graph_Adjacency_Matrix(void)
{
 
    int s, e, i;
    for (s = 1; s <= NUM_NODE; s++){
        for (e = 1; e <= NUM_NODE; e++){
            matrix[s][e] = NOT_CONNECTED;
        }
    }
 
    for (i = 0; i < NUM_EDGE; i++){
        matrix[edge[i].s][edge[i].e] = edge[i].cost;
    }
}
 

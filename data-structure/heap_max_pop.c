#include <stdio.h>
 
#define NUM_DATA    (8)
#define MAX_DATA    (NUM_DATA)
#define MAX_HEAP    (MAX_DATA+1)
#define LAST_NODE   (MAX_DATA)
 
int heap[MAX_HEAP];
int lastnode = 0;
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
int Heap_Pop_Maxheap(int *heap, int *lastnode, int *d)
{
    int n, c, lc, rc;
 
    if (*lastnode == 0) return 0; // heap이 비어 있으면 pop 실패
 
    // pop
    *d = heap[1]; 
    heap[1] = heap[(*lastnode)--]; // 마지막 노드를 맨 위로 올리고, lastnode 값 1 감소
 
    n = 1; lc = 2, rc = 3;
    while (lc <= *lastnode) { // 자식이 존재할 때
        if (lc == *lastnode) c = lc; // 자식이 하나라면 왼쪽 자식을 자식으로 설정
        else c = (heap[lc] > heap[rc]) ? lc : rc; // 값이 더 큰 놈을 자식으로 설정
 
        if (heap[n] < heap[c]) { // 자식이 더 크면 올림
            // swap
            int temp = heap[n];
            heap[n] = heap[c];
            heap[c] = temp;
 
            n = c; lc = n * 2; rc = lc + 1; // 노드 번호 갱신
        }
        else break;
    }
    return 1;
}

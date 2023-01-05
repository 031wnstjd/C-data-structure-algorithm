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
 
int Heap_Push_Maxheap(int *heap, int size, int *lastnode, int d)
{
    int n, p; // n : 비교 대상 노드, p : 부모 노드
 
    if (lastnode == size) return 0;
 
    heap[++*lastnode] = d;
 
    n = *lastnode; p = n / 2;
    while (p >= 1) { // 부모가 존재할 때
        if (heap[n] > heap[p]) {
            // swap
            int temp = heap[n];
            heap[n] = heap[p];
            heap[p] = temp;
 
            n = p; p = n / 2; // 비교 인덱스 재설정
        }
        else break;
    }
    return 1;
}

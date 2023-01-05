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
 
int Heap_Push_Minheap(int *heap, int size, int *lastnode, int d)
{
    int n, p;
 
    if (*lastnode == size) return 0; // 꽉 차 있으면 push 실패
 
    heap[++*lastnode] = d;
 
    n = *lastnode; p = n / 2;
    while (p >= 1) { // 부모가 존재할 때
        if (heap[n] < heap[p]) { // 부모의 값보다 작으면
            // swap
            int temp = heap[n];
            heap[n] = heap[p];
            heap[p] = temp;
 
            n = p; p = n / 2; // 비교 인덱스 재설정
        }
        else break; // 비교 끝
    }
    return 1;
}

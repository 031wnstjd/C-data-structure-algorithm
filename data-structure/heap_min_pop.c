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
 
int Heap_Pop_Minheap(int *heap, int *lastnode, int *d)
{
    int n, c, lc, rc; // n : 비교 대상, c : 결정된 n번 노드의 자식 번호, lc : 왼쪽 자식, rc : 오른쪽 자식
    if (*lastnode == 0) return 0; // 비어 있으면 pop 실패
 
    *d = heap[1];
    heap[1] = heap[(*lastnode)--]; // 연산자 우선순위 때문에 괄호 필수 (마지막 노드를 맨 위로 올리고, lastnode값 1 감소)
 
    n = 1; lc = 2; rc = 3;
    while (lc <= *lastnode) { // 자식이 존재할 때
        if (lc == *lastnode) c = lc; // 자식이 하나라면(==왼쪽 자식이 마지막 노드라면) 왼쪽 자식으로 선택
        else c = (heap[lc] < heap[rc]) ? lc : rc;
 
        if (heap[n] > heap[c]) {
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

#include <stdio.h>
 
#define NUM_DATA    (8)
#define MAX_DATA    (NUM_DATA)
#define MAX_HEAP    (MAX_DATA+1)
#define LAST_NODE   (MAX_DATA)
 
int heap[MAX_HEAP];
int lastnode = 0;
 
int Heap_Push_Minheap(int *heap, int size, int *lastnode, int d)
{
    int n,p,temp;
 
    if(*lastnode == size) return 0;
     
    heap[++(*lastnode)] = d;
 
    n = *lastnode; p = n/2;
 
    while(p>0)
    {
        if(heap[n] < heap[p])
        {
            temp = heap[n];
            heap[n] = heap[p];
            heap[p] = temp;
            n = p; p = n / 2;
        }
        else break;
    }
 
    return 1;
}
 
int Heap_Pop_Minheap(int *heap, int *lastnode, int *d)
{
    int n,c,lc,rc,temp;
 
    if(*lastnode == 0) return 0;
 
    *d = heap[1];
    heap[1] = heap[(*lastnode)--];
 
    n = 1; lc = 2; rc = 3;
    while(lc<=*lastnode)
    {
        if(*lastnode == lc) c = lc;
        else c = (heap[lc]<heap[rc])?(lc):(rc);
     
        if(heap[c]<heap[n])
        {
            temp = heap[c];
            heap[c] = heap[n];
            heap[n] = temp;
            n = c; lc = n*2; rc = lc+1;
        }
        else break;
    }
 
    return 1;
}
 
int Heap_Push_Maxheap(int *heap, int size, int *lastnode, int d)
{
    int n,p,temp;
 
    if(*lastnode == size) return 0;
     
    heap[++(*lastnode)] = d;
 
    n = *lastnode; p = n/2;
 
    while(p>0)
    {
        if(heap[n] > heap[p])
        {
            temp = heap[n];
            heap[n] = heap[p];
            heap[p] = temp;
            n = p; p = n / 2;
        }
        else break;
    }
 
    return 1;
}
 
int Heap_Pop_Maxheap(int *heap, int *lastnode, int *d)
{
    int n,c,lc,rc,temp;
 
    if(*lastnode == 0) return 0;
 
    *d = heap[1];
    heap[1] = heap[(*lastnode)--];
 
    n = 1; lc = 2; rc = 3;
    while(lc<=*lastnode)
    {
        if(*lastnode == lc) c = lc;
        else c = (heap[lc]>heap[rc])?(lc):(rc);
     
        if(heap[c]>heap[n])
        {
            temp = heap[c];
            heap[c] = heap[n];
            heap[n] = temp;
            n = c; lc = n*2; rc = lc+1;
        }
        else break;
    }
 
    return 1;
}
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
typedef int (*HEAP_PUSH)(int*,int,int*,int);
typedef int (*HEAP_POP)(int*,int*,int*);
 
void Heap_Sort(int *data, int cnt, int order)
{
    int i;
    int lastnode = 0;
 
    HEAP_PUSH arr_push[] = { Heap_Push_Maxheap , Heap_Push_Minheap };
    HEAP_POP arr_pop[] = { Heap_Pop_Maxheap , Heap_Pop_Minheap };
 
    HEAP_PUSH push = arr_push[order];
    HEAP_POP pop = arr_pop[order];
 
    for (i = 0; i < cnt; i++) {
        push(data - 1, cnt, &lastnode, data[i]); // push와 pop 메서드의 루트 노드 인덱스를 1로 설정했기 때문에 data-1로 매개변수 전달
    }
 
    for (i = cnt - 1; i >= 0; i--) {
        int ret;
        pop(data - 1, &lastnode, &ret);
        data[i] = ret; // heap에서 pop한 원소를 data 배열의 맨 뒤 부터 앞까지 차례대로 채움 (data 배열을 heap 공간, 정렬 결과 할당 공간으로 둘 다 이용)
    }
 
 
    /*
    if (order == 0) {
        for (i = 0; i < cnt; i++) {
            Heap_Push_Maxheap(data - 1, cnt, &lastnode, data[i]);
        }
        for (i = cnt - 1; i >= 0; i--) {
            int ret;
            Heap_Pop_Maxheap(data - 1, &lastnode, &ret);
            data[i] = ret;
        }
    }
    else {
        for (i = 0; i < cnt; i++) {
            Heap_Push_Minheap(data - 1, cnt, &lastnode, data[i]);
        }
        for (i = cnt - 1; i >= 0; i--) {
            int ret;
            Heap_Pop_Minheap(data - 1, &lastnode, &ret);
            data[i] = ret;
        }
    }*/
}

#include <stdio.h>
#include <malloc.h>
 
typedef struct _que
{
    int num;
    struct _que * next; 
}QUEUE;
 
QUEUE * Wrptr = (QUEUE *)0;;
QUEUE * Rdptr = (QUEUE *)0;;
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
int cnt_data;
int In_Queue(QUEUE * data)
{
    QUEUE *newnode = malloc(sizeof(QUEUE));
    if (newnode == (QUEUE*)0) return -1;
 
    *newnode = *data;
 
    if (Wrptr == (QUEUE*)0) { // 첫 데이터 enqueue
        Wrptr = Rdptr = newnode;
    }
    else {
        Wrptr->next = newnode; // 기존 끝 노드(최근 write)의 next를 newnode로 설정
        Wrptr = newnode; // newnode를 끝 노드로 설정
    }
 
    cnt_data++;
 
    return 1;
}
 
int Out_Queue(QUEUE * p)
{
    QUEUE *delnode; // 삭제 노드 임시 저장 (동적할당 해지를 위함)
    if (Rdptr == (QUEUE*)0) return -1; // 읽을 게 없으면 -1 리턴
     
    *p = *Rdptr; // Rdptr은 stack에서 Sptr과 동일한 역할
     
    delnode = Rdptr;
    Rdptr = Rdptr->next; // 기존 Rdptr 가리키는 데이터의 next 노드를 Rdptr이 가리키도록 재설정 (pop)
 
    free(delnode);
 
    if (Rdptr == (QUEUE*)0) Wrptr = (QUEUE*)0; // pop해서 더이상 읽을 게 없어졌다면 Wrptr도 null로 변경해줘야 함
 
    cnt_data--;
 
    return 1;
}
 
int Print_Queue(void)
{
    QUEUE* node = Rdptr;
 
    while (node) {
        printf("%d", node->num);
        node = node->next;
    }
    printf("\n");
 
    return cnt_data;
}
 
int Count_Full_Data_Queue(void)
{
    return cnt_data;
}

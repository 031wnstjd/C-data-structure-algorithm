#include <stdio.h>
#include <malloc.h>
 
typedef struct _stk
{
    int num;
    struct _stk * next; 
}STACK;
 
STACK * Sptr = (STACK *)0;
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
int Push_Stack(STACK *data)
{
    STACK *newnode = malloc(sizeof(STACK));
    if (newnode == (STACK*)0) return -1;
 
    *newnode = *data; // 새로운 노드 공간에 데이터 추가
 
    newnode->next = Sptr; // 기존 Sptr이 가리키고 있던 노드를 newnode의 next로 할당 (Sptr이 head역할)
    Sptr = newnode; // Sptr이 가리키는 노드를 새로운 노드로 변경
 
    return 1;
}
 
int Pop_Stack(STACK *p)
{
    STACK *delnode; // 삭제 노드 임시 저장 (동적할당 해지를 위함)
    if (Sptr == (STACK*)0) return -1; // stack이 비어있으면 -1 리턴 (항상 Sptr이 가리키는 노드를 pop하므로 이를 체크해야 함)
 
    *p = *Sptr;
 
    delnode = Sptr;
    Sptr = Sptr->next; // 기존 Sptr이 가리키는 데이터의 next 노드를 Sptr이 가리키도록 재설정 (pop)
 
    free(delnode);
    return 1;
}
 
int Print_Stack(void)
{
    int cnt = 0;
    STACK *node = Sptr;
    while (node) {
        printf("%d ", node->num);
        cnt++;
        node = node->next;
    }
    printf("\n");
    return cnt;
}
 
int Count_Full_Data_Stack(void)
{
    int cnt = 0;
    STACK *node = Sptr;
    while (node) {
        cnt++;
        node = node->next;
    }
    return cnt;
}

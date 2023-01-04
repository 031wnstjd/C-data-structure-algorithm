#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
typedef struct _score 
{
    int id;
    int jumsu;
    char name[10];
    struct _score  * next; 
}SCORE;
 
SCORE Head;
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
int Insert_Node(SCORE * head, SCORE * d)
{
    SCORE* prev = head;
    SCORE* newnode;
    while (prev->next) {
        if (prev->next->id > d->id) break;
        if (prev->next->id == d->id) return -2;
         
        prev = prev->next;
    }
 
    newnode = calloc(1, sizeof(SCORE));
    if (newnode == (SCORE*)0) return -1; // 메모리 동적할당 실패시 -1리턴
 
    *newnode = *d; // 새로운 노드에 값 복사
 
    newnode->next = prev->next; // 새로운 노드의 연결 관계부터 할당
    prev->next = newnode;
 
    return 1;
}

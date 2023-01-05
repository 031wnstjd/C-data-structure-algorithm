#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
typedef struct _score 
{
    int id;
    int jumsu;
    char name[10];
    struct _score  * next;
    struct _score  * prev;
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
        else if (prev->next->id == d->id) return -2;
 
        prev = prev->next;
    }
 
    newnode = calloc(1, sizeof(SCORE));
    if (newnode == (SCORE*)0) return -1;
 
    *newnode = *d;
 
    // 1. 새로운 노드의 연결 관계부터 정의
    newnode->prev = prev;
    newnode->next = prev->next;
 
    // 2. 앞, 뒤 노드의 연결 관계 재정의
    newnode->prev->next = newnode;
    if(newnode->next) newnode->next->prev = newnode; // newnode가 리스트의 마지막 노드가 아닌 경우에만 newnode의 다음 노드의 prev를 할당
}

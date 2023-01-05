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
 
SCORE * Search_Id_Node(SCORE * head, int id)
{
    for(;;)
    {
        if(head->next == (SCORE *)0x0) return (SCORE *)0x0;
        if(head->next->id == id) return head->next;      
        head = head->next;       
    }
}
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
int Delete_Node(SCORE * head, int id)
{
    SCORE* node = head->next; // double-linked-list에서 노드 "삭제"의 경우, prev(==head)가 아닌 node(==head->next)를 기준으로 진행
 
    while (node) {
        if (node->id == id) {
            node->prev->next = node->next; // 삭제 노드의 이전 노드의 연결 관계 재정의
            if(node->next) node->next->prev = node->prev; // 삭제 노드의 다음 노드의 연결 관계 재정의 (다음 노드가 존재할 때만)
            free(node);
            return 1;
        }
         
        node = node->next;
    }
 
    return -1;
}

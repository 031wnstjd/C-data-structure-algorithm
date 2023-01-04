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
 
int Delete_Node(SCORE * head, int id)
{
    SCORE* prev = head;
 
    while (prev->next) {
        if (prev->next->id == id) {
            SCORE* delnode = prev->next; // 메모리 할당 해제를 위해 삭제할 노드의 메모리 주소 임시 저장
            prev->next = prev->next->next; // 연결 관계 재정의
            free(delnode);
            return 1; // 성공
        }
        prev = prev->next;
    }
 
    return -1; // 실패 (동일한 id를 가진 노드가 없는 경우)
}

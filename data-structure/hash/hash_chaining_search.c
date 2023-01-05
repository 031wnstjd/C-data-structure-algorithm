#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
typedef struct _score 
{
    int id;
    int jumsu;
    char name[10];
    struct _score * next;
}SCORE;
 
#define MAX_ST      20
#define HASH_KEY    5
 
SCORE Hash_table[HASH_KEY];
 
int Get_Hash_Key(int id)
{
    return id % HASH_KEY;
}
 
void main(void)
{
 
}
 
// 작성한 코드를 아래에 넣으시오.
 
SCORE * Search_Data(int id)
{
    int hash = Get_Hash_Key(id);
    SCORE* node = Hash_table[hash].next;
 
    while (node) {
        if (node->id == id) return node;
        if (node->id > id) break; // 조회 id값 보다 커지면 데이터가 없다는 뜻이므로 break (오름차순 정렬된 chain이기 때문)
        node = node->next;
    }
 
    return (SCORE*)0; // 데이터 없으면 널포인터 리턴
}

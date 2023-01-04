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
 
int Delete_Data(int id)
{
    int hash = Get_Hash_Key(id);
    SCORE *prev = &Hash_table[hash];
    while (prev->next) {
        if (prev->next->id == id) {
            SCORE *delnode = prev->next;
            prev->next = prev->next->next;
            free(delnode);
            return 1;
        }
        if (prev->next->id > id) break; // 만약, 조회 id값보다 커지면 데이터가 존재하지 않는 것이므로 break (오름차순으로 정렬된 chain이기 때문)
 
        prev = prev->next;
    }
    return -1;
}

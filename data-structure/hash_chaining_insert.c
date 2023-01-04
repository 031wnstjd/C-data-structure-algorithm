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
 
 
int Insert_Data(SCORE * d)
{
    int hash;
    SCORE *newnode;
    SCORE *prev;
 
    hash = Get_Hash_Key(d->id);
    prev = &Hash_table[hash];
 
    while (prev->next) {
        if (prev->next->id > d->id) break; // id 오름차순 정렬 되어있음 (조회 성능 향상)
        if (prev->next->id == d->id) return -2; // 이미 데이터 있으면 -2리턴
         
        prev = prev->next;
    }
 
    newnode = malloc(sizeof(SCORE));
    if (newnode == (SCORE*)0) return -1;
 
    *newnode = *d;
 
    newnode->next = prev->next;
    prev->next = newnode;
 
    return 1;
}

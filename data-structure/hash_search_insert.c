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
#define STEP            1
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
    int hash_org = hash;
 
    do {
        if (Hash_table[hash].id != -1) return &Hash_table[hash]; // 해당 해시 값에 할당된 데이터가 존재한다면 해당 데이터의 주소를 리턴
        else hash = (hash + STEP) % MAX_ST; // STEP만큼 해시 값 이동
    } while (hash != hash_org);
 
    return (SCORE*)0; // 데이터가 없으면 null pointer 
}

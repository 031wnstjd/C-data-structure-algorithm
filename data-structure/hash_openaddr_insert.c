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
#define STEP        1
  
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
    int hash = Get_Hash_Key(d->id);
    int hash_org = hash;
 
    do {
        if (Hash_table[hash].id == -1) { // 해당 해시에 테이블 값이 비어있으면
            Hash_table[hash] = *d;
            return hash;
        }
        else hash = (hash + STEP) % MAX_ST; // STEP만큼 해시 값을 이동 (해시 테이블의 값이 비어 있는 위치를 찾아서)
    } while (hash != hash_org); // 처음에 할당된 해시 값으로 돌아올 때까지 반복
     
    return -1;
}

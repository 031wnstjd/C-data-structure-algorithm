#include <stdio.h>
#include <string.h>
 
// 정렬에 사용 할 자료
typedef struct _score 
{
    int id;
    int jumsu;
    char name[10];
}SCORE;
 
 
int main(void)
{
    return 0;
}
 
int Sort_Insertion(SCORE * d, int n, int ord, int (*comp)(SCORE * x, SCORE * y))
{
    int i, j;
    for (i = 0; i < n; i++) {
        // i번 인덱스 데이터의 삽입 위치 탐색, 삽입!
        SCORE temp = d[i];
        for (j = i; j > 0; j--) {
            if (comp(&temp, &d[j - 1]) * ord > 0) break;
            else d[j] = d[j - 1];
        }
        d[j] = temp;
    }
    return n;
}

#include <stdio.h>
#include <string.h>
 
// 정렬에 사용 할 자료
typedef struct _score 
{
    int id;
    int jumsu;
    char name[10];
}SCORE;
 
int Sort_Bubble(SCORE * d, int n, int order, int (*comp)(SCORE * x, SCORE * y))
{
    int i, j;
    for (int i = 0; i < n - 1; i++) { // stage 반복 loop : n-1 반복
        // stage 작업 : 전체 자료 영역 - 0 ~ n-1-i
        for (j = 0; j < n - 1 - i; j++) {
            if (comp(&d[j], &d[j + 1])*order > 0) {
                // swap
                SCORE temp;
                temp = d[j];
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
    return n;
}

int main(void)
{
    return 0;
}

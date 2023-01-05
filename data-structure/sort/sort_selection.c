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
 
int Sort_Select(SCORE * d, int n, int order, int (*comp)(SCORE * x, SCORE * y))
{
    int i, j;
    int last;
    SCORE temp;
    for (i = 0; i < n - 1; i++) {
        // 0 ~ n-1-i : 우선순위가 가장 낮은 녀석 선택
        int sel = 0;
        for (j = 1; j <= n - 1 - i; j++) {
            if (comp(&d[j], &d[sel])*order > 0) sel = j;
        }
 
        last = n - 1 - i;
        if (sel != last) {
            temp = d[last];
            d[last] = d[sel];
            d[sel] = temp;
        }
    }
    return n;
}

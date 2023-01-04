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
 
int Sort_Quick(SCORE *d, int order, int s, int e, int(*comp)(SCORE * x, SCORE * y))
{
    int p, t, l;
    SCORE temp;
 
    if (s >= e) return 0;
 
    p = e;
    for (t = s, l = s; l < e; l++) {
        if (comp(&d[l], &d[p]) * order < 0) {
            if (l != t) {
                temp = d[l];
                d[l] = d[t];
                d[t] = temp;
            }
            t++;
        }
    }
 
    if (p != t) {
        temp = d[p];
        d[p] = d[t];
        d[t] = temp;
    }
    Sort_Quick(d, order, s, t - 1, comp); // s~t-1 정렬
    Sort_Quick(d, order, t + 1, e, comp); // t+1~e 정렬
 
    return e - s + 1;
}

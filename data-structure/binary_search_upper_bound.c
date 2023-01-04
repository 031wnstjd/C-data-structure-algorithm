#include <stdio.h>
#include <string.h>
 
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
 
int Binary_Search_Upper(SCORE *src, int s,int e,SCORE *d,int (*comp)(SCORE* x,SCORE *y))
{
    int m, ret, sol = -1;
 
    while (s <= e) {
        m = (s + e) / 2;
        ret = comp(&src[m], d);
        if (ret <= 0) {
            sol = m;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return sol;
}

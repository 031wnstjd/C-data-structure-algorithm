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
 
int Sort_Merge(SCORE *d, SCORE *tmp, int order, int s, int e, int (*comp)(SCORE * x, SCORE * y))
{
    int m;
    int idx1, idx2, idxtmp;
    if (s >= e) return 1;
 
    // 1. 영역 나누기 : s ~ m, m+1 ~ e
    m = (s + e) / 2;
 
    // 2. 각 영역 Merge Sort
    Sort_Merge(d, tmp, order, s, m, comp);
    Sort_Merge(d, tmp, order, m+1, e, comp);
 
    // 3. Merge
    idx1 = s, idx2 = m+1, idxtmp = s;
    while (idx1 <= m && idx2 <= e) {
        if (comp(&d[idx1], &d[idx2]) * order < 0) tmp[idxtmp++] = d[idx1++];
        else tmp[idxtmp++] = d[idx2++];
    }
 
    while (idx1 <= m) tmp[idxtmp++] = d[idx1++];
    while (idx2 <= e) tmp[idxtmp++] = d[idx2++];
 
    for (idxtmp = s; idxtmp <= e; idxtmp++) d[idxtmp] = tmp[idxtmp];
 
    return e - s + 1;
}

#include <stdio.h>
#include <stdlib.h>

struct strf
{
    int pid, rbt, at, bt, ct, st, tat, wt, rt;
};

int comp(const void *n1, const void *n2)
{
    int l = ((struct strf *)n1)->at;
    int r = ((struct strf *)n2)->at;
    return (l - r);
}
int main()
{
    int n;
    printf("\nEnter the number of process: ");
    scanf("%d", &n);
    struct strf arr[n];
    printf("\nEnter the arrival and burst time of all process");
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter at and bt of process P%d: ", i + 1);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
    }

    qsort((void *)arr, n, sizeof(arr[0]), comp);
    
    return 0;
}
#include <stdio.h>
#include "include/talloc.h"
#include "include/tfree.h"

int main(void) 
{
    int *q = (int *)t_allocx(128 * sizeof(int));
    printf("%p\n", q);

    for (int i = 0; i < 128; i++) q[i] = i;
    for (int j = 0; j < 128; j++) printf("%d\n", q[j]);

    t_freex(q);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "include/turboalloc.h"

#define INT_NUMBER 16

int main(void) 
{
    /*
    int *q = (int *)t_allocw(128 * sizeof(int));
    printf("%p\n", q);

    for (int i = 0; i < 128; i++) q[i] = i;
    for (int j = 0; j < 128; j++) printf("%d\n", q[j]);
    t_freew(q);
    */

    uint16_t s = 0x00;
    int *k = (int *)t_callocw(INT_NUMBER, sizeof(int));
    printf("%p\n", k);
    //for (int y = 0; y < INT_NUMBER - 1; y++) { k[y] = y; s++; }
    for (int h = 0; h < INT_NUMBER - 1; h++) printf("%d\n", k[h]);
    printf("%d\n", s);
    t_freew(k);

    return 0;
}
#include <stdint.h>
#include <stdio.h>

#ifndef TURBOALLOC_H
#define TURBOALLOC_H

void *t_allocw(size_t size);
void *t_callocw(size_t nb, size_t size);
void t_freew(void *ptr);

#endif

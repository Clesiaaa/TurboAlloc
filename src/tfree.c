#include <stdio.h>
#include <unistd.h>
#include "../include/tfree.h"
#include "../include/block.h"
#include "../include/tools.h"

void t_free(void *ptr)
{
    block_t *block = (block_t*)((char *)ptr - sizeof(block_t));
    block->is_free = 1;
}

void t_freex(void *ptr)
{
    node_t *node = (node_t*)((char *)ptr - sizeof(node_t));
    node->is_free = 1;
}

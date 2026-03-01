#include <stdio.h>
#include <unistd.h>
#include "../include/turboalloc.h"
#include "../include/block.h"
#include "../include/tools.h"


ball_t *heap_startw = NULL;
void *t_allocw(size_t size) {
    
    ball_t *current_ball = heap_startw;

    if (current_ball == NULL) {
        ball_t *new_ball_root = sbrk(size + sizeof(ball_t));
        *new_ball_root = create_ball(size);
        heap_startw = new_ball_root;
        return (char *)heap_startw + sizeof(ball_t);
    }

    ball_t *new_ball = sbrk(size + sizeof(ball_t));
    *new_ball = create_ball(size);
    heap_startw = insert_avl(current_ball, new_ball);
    return (char *)new_ball + sizeof(ball_t);
}

void t_freew(void *ptr) {
    if (ptr == NULL) return;
    ball_t *ball = (ball_t *)((char *)ptr - sizeof(ball_t));
    if (ball->is_free) return; 
    size_t ball_size = ball->size;
    //printf("%ld @ %p\n", ball_size, ball);
    ball_t *tmp = heap_startw;
    heap_startw = delete_avl(tmp, ball_size);
    ball->is_free = 1;
}

void *t_callocw(size_t nb, size_t size)
{       
    void *first_ptr = NULL;
    ball_t *current_ball = heap_startw;

    for (uint16_t i = 0x00; i < nb; i++) {

        if (current_ball == NULL) {
            ball_t *new_ball_root = sbrk(size + sizeof(ball_t));
            if (new_ball_root == (void *)-1) return NULL;
            *new_ball_root = create_ball(size);
            heap_startw = new_ball_root;
            if (first_ptr == NULL) first_ptr = (char *)heap_startw + sizeof(ball_t);
        } else {
            ball_t *new_ball = sbrk(size + sizeof(ball_t));
            if (new_ball == (void *)-1) return NULL; 
            *new_ball = create_ball(size);
            heap_startw = insert_avl(current_ball, new_ball);
            if (first_ptr == NULL) first_ptr = (char *)new_ball + sizeof(ball_t);
        }
    }
    fill(current_ball, size);
    return first_ptr;
}
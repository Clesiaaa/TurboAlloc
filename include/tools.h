#include "block.h"

#ifndef TOOLS_H
#define TOOLS_H

#define MAX(x,y) ((x) > (y) ? (x) : (y))

uint8_t height(ball_t *ball);
ball_t *insert_avl(ball_t *ball, ball_t *a);
int8_t balance(ball_t *ball);
ball_t *delete_avl(ball_t *ball, size_t size);
ball_t *rotate_left(ball_t *ball);
ball_t *rotate_right(ball_t *ball);
ball_t *equilibrate(ball_t *ball);
ball_t *min_tree(ball_t *ball);
ball_t *successor(ball_t *ball);
ball_t create_ball(size_t size);
ball_t *fill(ball_t *ball, size_t size);

#endif
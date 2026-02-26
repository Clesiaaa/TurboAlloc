#include <stdint.h>
#include <stdio.h>

#ifndef BLOCK_H
#define BLOCK_H

typedef struct block_t {
    size_t size;
    uint8_t is_free;
    struct block_t *next;
} block_t;

typedef struct node_t {
    struct node_t *left;
    uint8_t is_free;
    size_t size;
    struct node_t *right;
} node_t;

typedef struct ball_t {
    struct ball_t *left;
    uint8_t is_free;
    struct ball_t *father;
    size_t size;
    struct ball_t *right;
} ball_t;

#endif
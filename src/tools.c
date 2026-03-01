#include <stdio.h>
#include <string.h>
#include <../include/tools.h>

uint8_t height(ball_t *ball) {
    if (ball == NULL) return 0;
    return 1 + MAX(height(ball->left), height(ball->right));
}

int8_t balance(ball_t *ball) {
    if (ball == NULL) return 0;
    return height(ball->left) - height(ball->right);
}

ball_t *insert_avl(ball_t *ball, ball_t *a) {
    
    if (ball == NULL) return a;
    else if (a->size < ball->size) { 
        ball->left = insert_avl(ball->left, a);
        return equilibrate(ball);
    }
    else if (a->size == ball->size) { 
        ball->left = insert_avl(ball->left, a);
        return equilibrate(ball);
    }
    else if (a->size > ball->size) { 
        ball->right = insert_avl(ball->right, a);
        return equilibrate(ball);    
    }
    return ball;
};

ball_t *equilibrate(ball_t *ball){
    
    if (balance(ball) < 1) {
        if (balance(ball->left) >= 0) {
            return rotate_right(ball);
        } else {
            ball->left = rotate_right(ball->left);
            return rotate_left(ball);
        }
    }

    if (balance(ball) > 1) {
        if (balance(ball) >= 0) {
            return rotate_left(ball);
        } else {
            ball->right = rotate_right(ball->right);
            return rotate_left(ball);
        }
    }
    return ball;
}

ball_t *rotate_left(ball_t *ball) {
    ball_t *temp = ball;
    ball = ball->right;
    ball_t *kid_left = ball->left;
    ball->left = temp;
    temp->right = kid_left;
    return ball;
};

ball_t *rotate_right(ball_t *ball) {
    ball_t *temp = ball;
    ball = ball->left;
    ball_t *kid_right = ball->right;
    ball->right = temp;
    temp->left = kid_right;
    return ball;
};

ball_t *delete_avl(ball_t *ball, size_t size) {
    if (ball == NULL) return ball;
    if (size < ball->size) {
        ball->left = delete_avl(ball->left, size);
    } else if (size > ball->size) {
        ball->right = delete_avl(ball->right, size);   
    } else {
        if (ball->left != NULL && ball->right == NULL) {
            return ball->left;                          
        } else if (ball->left == NULL && ball->right != NULL) {
            return ball->right;                        
        } else if (ball->left == NULL && ball->right == NULL) {
            return NULL;                               
        } else {
            ball_t *succ = successor(ball);
            ball->size = succ->size;
            ball->right = delete_avl(ball->right, succ->size); 
        }
    }
    return ball;
}
ball_t *successor(ball_t *ball) {
    if (ball->right != NULL) return min_tree(ball->right);

    ball_t *father = ball->father;
    while (father != NULL && ball == father->right) {
        ball = father;
        father = father->father;
    }
    return father;
}

ball_t *min_tree(ball_t *ball) {
    ball_t *current_ball = ball;
    while (current_ball->left != NULL) current_ball = current_ball->left;
    return current_ball;
}

ball_t create_ball(size_t size) {
    ball_t new_ball;
    new_ball.father = NULL;
    new_ball.left = NULL;
    new_ball.right = NULL;
    new_ball.is_free = 0;
    new_ball.size = size;
    return new_ball;
}

ball_t *fill(ball_t *ball, size_t size)
{
    if (ball == NULL) return NULL;
    char *data = (char *)ball + sizeof(ball_t);
    for (size_t i = 0; i < size; i++)
        data[i] = 0;
    ball->left = fill(ball->left, size);
    ball->right = fill(ball->right, size);
    return ball;
}
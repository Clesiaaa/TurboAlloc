#include <stdio.h>
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

ball_t *delete_val(ball_t *ball, size_t size) {
    if (ball == NULL) return ball;
    if (size < ball->size) {
        ball->left = delete_val(ball->left, size);
    } else if (size > ball->size) {
        ball->right = delete_val(ball->right, size);   
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
            ball->right = delete_val(ball->right, succ->size); 
        }
    }
    return equilibrate(ball);
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
    while (ball->left != NULL) ball = ball->left;
    return ball;
}
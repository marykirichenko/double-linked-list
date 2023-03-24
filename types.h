
// protect against 'multiple definition' error when including more than once
#ifndef _TYPES_H_
#define _TYPES_H_
typedef struct node {
    void* data;
    struct node* next;
    struct node* previous;
} node_t;


typedef struct point {
    int x;
    int y;
}point_t;

typedef int (*comparator_t)(void*, void*);

#endif

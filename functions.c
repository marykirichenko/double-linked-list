#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
// function definitions

void show(node_t* head, int typeOption) {
    printf("\n");
    if (head == NULL) {
        printf("List is empty");
        return;
    }
    node_t* curr = head;
    switch (typeOption) {
    case 1:
        do {
            int* val = (int*)curr->data;
            printf("%d ", *val);
            curr = curr->next;
        } while (curr != NULL);
        break;
    case 2:
        do {
            double* val = (double*)curr->data;
            printf("%lf ", *val);
            curr = curr->next;
        } while (curr != NULL);
        break;
    case 3:
        do {
            point_t* val = (point_t*)curr->data;
            printf("(%d, %d) ", val->x, val->y);
            curr = curr->next;
        } while (curr != NULL);
        break;
    default:
        printf("Invalid type");
        break;
    }
}

void insert_front(node_t** head, void* data) {
    if (*head == NULL) {
        *head = (node_t*)malloc(sizeof(node_t));
        (*head)->data = data;
        (*head)->previous = NULL;
        (*head)->next = NULL;
    }
    else {
        node_t* curr;
        curr = (node_t*)malloc(sizeof(node_t));
        curr->data = data;
        curr->previous = NULL;
        curr->next = (*head);
        (*head)->previous = curr;
        *head = curr;
    }
}

void insert_back(node_t** head, void* data) {
    if (*head == NULL) {
        *head = (node_t*)malloc(sizeof(node_t));
        (*head)->data = data;
        (*head)->previous = NULL;
        (*head)->next = NULL;
    }
    else {
        node_t* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = (node_t*)malloc(sizeof(node_t));
        curr->next->data = data;
        curr->next->previous = curr;
        curr->next->next = NULL;
    }
}

void remove_front(node_t** head) {
    if (*head == NULL) {
        return;
    }
    node_t* old_head = *head;
    *head = old_head->next;
    if (*head != NULL) {
        (*head)->previous = NULL;
    }
    free(old_head->data);
    free(old_head);
}

void remove_back(node_t** head) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->next == NULL) {
        free((*head)->data);
        free(*head);
        *head = NULL;
    }
    else {
        node_t* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->previous->next = NULL;
        free(curr->data);
        free(curr);
    }
}

int compare_int(void* a, void* b) {
    int* val1 = (int*)a;
    int* val2 = (int*)b;
    if (*val1 < *val2) return -1;
    else if (*val1 == *val2) return 0;
    else return 1;
}

int compare_double(void* a, void* b) {
    double* val1 = (double*)a;
    double* val2 = (double*)b;
    if (*val1 < *val2) return -1;
    else if (*val1 == *val2) return 0;
    else return 1;
}

int compare_points(void* a, void* b) {
    point_t* val1 = (point_t*)a;
    point_t* val2 = (point_t*)b;
    if (val1->x < val2->x) return -1;
    else if (val1->x == val2->x) {
        if (val1->y < val2->y) return -1;
        else if (val1->y == val2->y) return 0;
        else return 1;
    }
    else return 1;
}

void sort(node_t** head, comparator_t comparator) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    node_t* curr = *head;
    node_t* next = curr->next;
    while (next != NULL) {
        node_t* tmp = *head;
        while (tmp != next) {
            if (comparator(tmp->data, next->data) > 0) {
                void* temp = tmp->data;
                tmp->data = next->data;
                next->data = temp;
            }
            else {
                tmp = tmp->next;
            }
        }
        curr = curr->next;
        next = curr->next;
    }
}



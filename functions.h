//functions declarations 

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H

#include "types.h"

void show(node_t* head, int typeOption);

void insert_front(node_t** head, void* data);

void insert_back(node_t** head, void* data);

void remove_front(node_t** head);

void remove_back(node_t** head);

int compare_int(void* a, void* b);

int compare_double(void* a, void* b);

int compare_points(void* a, void* b);

void sort(node_t** head, comparator_t comparator);

#endif




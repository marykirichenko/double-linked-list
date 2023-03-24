#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "functions.h"

// main app

int main() {
    node_t* head;
    head = (node_t*)malloc(sizeof(node_t));
    head = NULL;
    int typeOption = 0;

    printf("1.Typ int\n");
    printf("2.Typ double.\n");
    printf("3.Structura points.\n");

    scanf("%i", &typeOption);

    int option = 1;
    while (option != 0) {
        printf("State:");
        show(head, typeOption);

        printf("\n1. Dodac element na poczatek listy.\n");
        printf("2. Dodac element na koniec listy.\n");
        printf("3. Usunac element z poczatku listy\n");
        printf("4.  Usunac element z koncu listy\n");
        printf("5. Posortowac liste\n");
        printf("0. Zakonczyc program.\n");

        scanf("%i", &option);

        switch (option) {
        case 1: {
            if (typeOption == 3) {
                point_t* new_point = (point_t*)malloc(sizeof(point_t));
                printf("\nEnter x: ");
                scanf("%d", &(new_point->x));
                printf("Enter y: ");
                scanf("%d", &(new_point->y));
                insert_front(&head, new_point);
                break;
            }
            printf("Podaj liczbe do dodaniay: ");
            if (typeOption == 1) {
                int* val = (int*)malloc(sizeof(int));
                scanf("%i", val);
                insert_front(&head, val);
            }
            if (typeOption == 2) {
                double* val = (double*)malloc(sizeof(double));
                scanf("%lf", val);
                insert_front(&head, val);
            }

           
            break;
        }
        case 2: {
            if (typeOption == 3) {
            point_t* new_point = (point_t*)malloc(sizeof(point_t));
            printf("\nEnter x: ");
            scanf("%d", &(new_point->x));
            printf("Enter y: ");
            scanf("%d", &(new_point->y));
            insert_back(&head, new_point);
            break;
           }
            printf("Podaj liczbe do dodania na poczatek listy: ");
            if (typeOption == 1) {
                int* val = (int*)malloc(sizeof(int));
                scanf("%i", val);
                insert_back(&head, val);
            }
            if (typeOption == 2) {
                double* val = (double*)malloc(sizeof(double));
                scanf("%lf", val);
                insert_back(&head, val);
            }


            break;
        }
        case 3: {
            remove_front(&head);
            break;
        }
        case 4: {
            remove_back(&head);
            break;
        }
        case 5: {
            printf("Posortowana lista:\n");
            if (typeOption == 1) sort(&head, compare_int);
            if (typeOption == 2) sort(&head, compare_double);
            if (typeOption == 3) sort(&head, compare_points);
            break;
        }
        case 0: {
            printf("Koniec programu.\n");
            break;
        }
        default: {
            printf("Nieprawidlowa opcja. Sprobuj ponownie.\n");
            break;
        }
        }
    }
}

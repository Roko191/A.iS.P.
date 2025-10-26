#pragma once

#include <stdio.h>

typedef struct Person {
    char *name;
    char *surname;
    int year;
    struct Person* next;
} Person;

int createNode(Person** node, const char *name, const char *surname, int year);
int addNodeAtStart(Person *head, const char *name,const char *surname, int year);
int printList(Person* head);
int addNodeAtEnd(Person* head,const char *name, const char *surname, int year);
int findElement(Person* head, const char* surname);
int deleteBySurname(Person **head, const char *surname);
void cleanMemory(Person* head);

// LAB3  - Nove funkcije
int addAfterSurname(Person **head, const char *surname, const char *addName, const char *addSurname, int year);
int addBeforeSurname(Person **head, const char *surname, const char *addName, const char *addSurname, int year);
int sortListBySurname(Person* head);
int createListFromFile(FILE* f_list, Person** head);
int printListToFile(FILE* f_print, Person* head);
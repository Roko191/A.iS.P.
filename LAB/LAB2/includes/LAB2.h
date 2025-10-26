#pragma once

typedef struct Person {
    char *name;
    char *surname;
    int year;
    struct Person* next;
} Person;

int createNode(Person** node, const char *name, const char *surname, int year);
int addNodeAtStart(Person *head, const char *name,const char *surname, int year);
int printList(Person* head);
int addNodeAtEnd(Person* head, char *name, char *surname, int year);
int findElement(Person* head, char* surname);
int deleteBySurname(Person **head, const char *surname);
void cleanMemory(Person* head);
#pragma once

#include <stdio.h>


typedef struct Node {
    int num;
    struct Node* next;
} Node;

int readFromFile_addToList(FILE* f_list, Node* head);
int printList(Node* head);
int unionOfList(Node** rList, Node* list1, Node* list2);
int intersectionOfList(Node** rList, Node* list1, Node* list2);
void cleanMemory(Node* head);
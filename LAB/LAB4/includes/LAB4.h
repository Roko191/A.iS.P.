#pragma once

#include <stdio.h>


typedef struct Node {
    int num;
    int expo;
    struct Node* next;
} Node;

int readFromFile_addToList(FILE* f_list, Node* head);
int printList(Node* head);
int sumListPolinom(Node** rList, Node* list1, Node* list2, int debug);
int multiplyListPolinom(Node** rList, Node* list1, Node* list2);
void cleanMemory(Node* head);
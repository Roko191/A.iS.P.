#pragma once

#include <stdint.h>

//
typedef struct Node {
    int el;
    struct Node* next;
} Node;


uint32_t genSeed(int verbose, int debug);
int push(Node* stack, int verbose);
int printList(const Node* head);
int pop(Node* stack);
int enqueue(Node* queue, int verbose);
int dequeue(Node* queue);
int cleanMemory(Node* head);
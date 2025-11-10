#pragma once

#include <stdint.h>

//
typedef struct Node {
    int el;
    struct Node* next;
} Node;


uint32_t genSeed(int verbose, int debug);
int push(Node* p_head, int verbose);
int printList(const Node* head);
int pop(Node* p_head);
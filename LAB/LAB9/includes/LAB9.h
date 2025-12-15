#pragma once

#include <stdint.h>

typedef struct Node {
    int el;
    struct Node* next;
} Node;

typedef struct pq_Node {
    int el;
    int priority;
    struct pq_Node* next;
} pq_Node;


// GENERAL
uint32_t genSeed(int verbose, int debug);
uint64_t now_ms();
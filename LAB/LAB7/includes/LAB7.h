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
int n_printList(const Node* p_head);
int pq_printList(const pq_Node* p_head);
int pq_cleanMemory(pq_Node* head);
int n_cleanMemory(Node* head);

// STACK
int push(Node* stack, int verbose);
int pop(Node* stack);


// Queue and priority queue
int pq_enqueue(pq_Node* p_queue, int p_verbose);
int n_enqueue(Node* p_queue, int p_verbose);

int dequeue_node(Node* p_queue);
int dequeue_pq_Node(pq_Node* p_queue);


// Macros with generic
#define dequeue(x) _Generic((x), \
                            Node*: dequeue_node, \
                            pq_Node*: dequeue_pq_Node \
)(x)

#define enqueue(x, verbose) _Generic((x) , \
                            Node*: n_enqueue, \
                            pq_Node*: pq_enqueue \
)(x, verbose)

#define cleanMemory(x) _Generic((x),  \
                                Node*: n_cleanMemory, \
                                pq_Node*: pq_cleanMemory \
)(x)

#define printList(x) _Generic((x), \
                              Node*: n_printList, \
                              pq_Node*: pq_printList \
)(x)
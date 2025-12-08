#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include "../LAB7.h"

uint32_t genSeed(int verbose, int debug){
    uint32_t s_seed = 0;

    if(debug){
        if(verbose) printf("Debug mode enabled using constant for seed\n");
        return s_seed;
    }

    int s_fd_urandom = open("/dev/urandom", O_RDONLY);
    if(s_fd_urandom == -1){
        perror("[WARN] Failed to open /dev/uranom: ");
    } else {
        if(verbose) printf("[VERBOSE] /dev/urandom opened succesfully\n");
    }

    // We dont need to crash if /dev/urandom fails to open
    if(s_fd_urandom >= 0) read(s_fd_urandom, &s_seed, sizeof(s_seed));
    
    s_seed += time(NULL) + getpid();

    if(verbose) printf("[VERBOSE] seed: %u\n", s_seed);

    close(s_fd_urandom);

    return s_seed;
}


int n_printList(const Node* p_head){
    if(!p_head) return -1;

    Node* curr = p_head -> next;
    while(curr != NULL){
        printf("%d", curr -> el);
        if(curr -> next != NULL) printf(" -> "); 
        curr = curr -> next;
    }
    printf("\n");

    return 0;
}

int pq_printList(const pq_Node* p_head){
    if(!p_head) return -1;

    pq_Node* curr = p_head -> next;
    while(curr != NULL){
        printf("%d (%d)", curr -> el, curr -> priority);
        if(curr -> next != NULL) printf(" -> "); 
        curr = curr -> next;
    }
    printf("\n");

    return 0;
}


int n_createNode(Node** p_node, int verbose){
    if(!p_node){
        return -1;
    }

    Node* tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        return -2;
    }

    int num = rand() % (100 - 10 + 1) + 10;
    if(verbose) printf("Rand num: %d\n", num);
    tmp -> el = num;
    tmp -> next = NULL;

    *p_node = tmp;

    return 0;
}

int pq_createNode(pq_Node** p_node, int verbose){
    if(!p_node){
        return -1;
    }

    pq_Node* tmp = (pq_Node*)malloc(sizeof(pq_Node));
    if(!tmp){
        return -2;
    }

    int num = rand() % (100 - 10 + 1) + 10;
    int p =  rand() %  5 + 1;
    if(verbose) printf("Rand num: %d\n", num);
    if(verbose) printf("Priority: %d\n", p);
    tmp -> el = num;
    tmp -> priority = p;
    tmp -> next = NULL;

    *p_node = tmp;

    return 0;
}


#define createNode(ptr, verbose) _Generic((ptr),          \
    Node**: n_createNode,                                \
    pq_Node**: pq_createNode                              \
)(ptr, verbose)

int push(Node* p_head, int p_verbose){
    if(!p_head){
        return -1;
    }

    Node* newNode;
    if(createNode(&newNode, p_verbose)){
        return -2;
    }

    if(p_head -> next != NULL){
        newNode -> next = p_head -> next;
    }

    p_head -> next = newNode;

    return 0;
}


int n_enqueue(Node* p_queue, int p_verbose){
    if(!p_queue){
        return -1;
    }
 

    if(p_queue -> next == NULL){
        Node* newNode;
        if(createNode(&newNode, p_verbose)){
            return -2;
        }

        p_queue -> next = newNode;
        return 0;
    }

    Node* curr = p_queue -> next;    
    while(curr->next != NULL){
        curr = curr-> next;
    }

    
    Node* newNode;
    if(createNode(&newNode , p_verbose)){
        return -2;
    }

    curr -> next = newNode;

    return 0;
}


int pq_enqueue(pq_Node* p_queue, int p_verbose){
    if(!p_queue){
        return -1;
    }
 

    if(p_queue -> next == NULL){
        pq_Node* newNode;
        if(createNode(&newNode, p_verbose)){
            return -2;
        }

        p_queue -> next = newNode;
        return 0;
    }

    pq_Node* newNode;
    if(createNode(&newNode, p_verbose))
        return -2;

    pq_Node* prev = p_queue;
    pq_Node* curr = p_queue->next;

    // tražimo prvo mjesto gdje je curr->priority > newNode->priority
    // ili dok je curr != NULL
    // tako novi node ide ispred svih sa istim prioritetom ili većim
    while(curr != NULL && curr->priority < newNode->priority){
        prev = curr;
        curr = curr->next;
    }

    // umetanje
    newNode->next = curr;
    prev->next = newNode;

    return 0;

}

int deleteFirst_Node(Node* p_head){
    if(!p_head){
        return -1;
    }

    Node* toFree = p_head -> next;
    p_head->next = p_head->next->next;
    free(toFree);

    return 0;
}

int deleteFirst_pq_Node(pq_Node* p_head){
    if(!p_head){
        return -1;
    }

    pq_Node* toFree = p_head -> next;
    p_head->next = p_head->next->next;
    free(toFree);

    return 0;
}

#define deleteFirst(x) _Generic((x),   \
                                Node*: deleteFirst_Node, \
                                pq_Node*: deleteFirst_pq_Node \
)(x)

int pop(Node* p_head){
    return deleteFirst(p_head);
}

int dequeue_node(Node* p_queue){
    return deleteFirst(p_queue);
}

int dequeue_pq_Node(pq_Node* p_queue){
    return deleteFirst(p_queue);
}

#define dequeue(x) _Generic((x), \
                            Node*: dequeue_node, \
                            pq_Node*: dequeue_pq_Node \
)(x)

int n_cleanMemory(Node* head){
    Node* toClean;
    
    if(head -> next == NULL){
        return -1;
    }

    while(head != NULL){
        toClean = head;
        head = head ->next;
        free(toClean);
    }

    return 0;
}

int pq_cleanMemory(pq_Node* head){
    pq_Node* toClean;
    
    if(head -> next == NULL){
        return -1;
    }

    while(head != NULL){
        toClean = head;
        head = head ->next;
        free(toClean);
    }

    return 0;
}

#define cleanMemory(x) _Generic((x),  \
                                Node*: n_cleanMemory, \
                                pq_Node*: pq_cleanMemory \
)(x)



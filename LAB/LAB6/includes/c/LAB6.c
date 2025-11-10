#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#include "../LAB6.h"

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


int printList(const Node* p_head){
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


int createNode(Node** p_node, int verbose){
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

    *p_node = tmp;

    return 0;
}


int push(Node* p_head, int p_verbose){
    if(!p_head){
        return -1;
    }
 

    if(p_head -> next == NULL){
        Node* newNode;
        if(createNode(&newNode, p_verbose)){
            return -2;
        }

        p_head -> next = newNode;
        return 0;
    }

    Node* curr = p_head -> next;    
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

int deleteFirst(Node* p_head){
    if(!p_head){
        return -1;
    }

    Node* toFree = p_head -> next;
    p_head->next = p_head->next->next;
    free(toFree);

    return 0;
}

int pop(Node* p_head){
    return deleteFirst(p_head);
}
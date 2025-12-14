#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../LAB8.h"

FILE* getFile(const char* path){
    if(!path){
        return NULL;
    }

    FILE* file = fopen(path, "r");
    if(!file){
        perror("Could not open file for postfix: ");
        return NULL;
    }

    return file;
}

int createNode(Node** p_node, int el){
    if(!p_node){
        return -1;
    }

    Node* tmp = (Node*)malloc(sizeof(Node));
    if(!tmp){
        return -2;
    }

    tmp -> el = el;
    tmp -> next = NULL;

    *p_node = tmp;

    return 0;
}

int push(Node* p_head, float el){
    if(!p_head){
        return -1;
    }

    Node* newNode;
    if(createNode(&newNode, el)){
        return -2;
    }

    if(p_head -> next != NULL){
        newNode -> next = p_head -> next;
    }

    p_head -> next = newNode;

    return 0;
}

int printList(Node* p_head){
    if(!p_head) return -1;

    Node* curr = p_head -> next;
    while(curr != NULL){
        printf("%.2f", curr -> el);
        if(curr -> next != NULL) printf(" -> "); 
        curr = curr -> next;
    }
    printf("\n");

    return 0;
}

int getLastEl(Node* p_head){
    if(!p_head){
        return -1;
    }

    if(p_head -> next == NULL){
        printf("[WARN] (getLastEl) Input stack does not have any value! Something wrong! \n");
        return -1;
    }

    return p_head -> next -> el;
}

int pop(Node* p_head){
    if(!p_head){
        return -1;
    }

    Node* toFree = p_head -> next;
    p_head->next = p_head->next->next;
    free(toFree);

    return 0;
}

float postfix(const char* pf_e, size_t size){
    if(!pf_e || size == 0){
        return -1;
    }

    Node* stack = malloc(sizeof(Node));
    if(!stack){
        perror("Failed to alloc head for stack: ");
        return -2;
    }
    stack -> next = NULL;


    for(int i=0;  i < size; i++){
        // U slucaju da je broj dodajemo na stack
        if(isdigit(pf_e[i])){
                char* end;
                float val = strtof(&pf_e[i], &end);
                printf("[INFO] postfix val thats gonna be pushed: %.2f\n", val);
                push(stack, val);
                printList(stack);
                i += (end - &pf_e[i]) - 1;
                continue;
        } else {
            // Obavimo zadanu matematicku operaciju u slucaju da nije
            // PREDPOSTAVKA JE DA IMAMO VALJAN POSTIFIX izraz
            switch(pf_e[i]){
                case '+': {
                    float second = getLastEl(stack);
                    pop(stack);
                    float first = getLastEl(stack);
                    pop(stack);

                    push(stack,(float)first + second);

                    break;
                }
                case '-': {
                    float second = getLastEl(stack);
                    pop(stack);
                    float first = getLastEl(stack);
                    pop(stack);

                    push(stack, (float)first - second);

                    break;
                }
                case '*': {
                    float second = getLastEl(stack);
                    pop(stack);
                    float first = getLastEl(stack);
                    pop(stack);

                    push(stack,first * second);

                    break;
                }

                case '/': {
                    float second = getLastEl(stack);
                    pop(stack);
                    float first = getLastEl(stack);
                    pop(stack);

                    push(stack, first / second);

                    break;
                }
            }
        } 
        
    }
    return stack -> next -> el;
}



int readFileAndCalculate(FILE* file){
    if(!file){
        return -1;
    }

    size_t sizeLine;
    char* line = NULL;

    while(getline(&line, &sizeLine, file) != -1){
        // Jednotavmo comment system
        if(line[0] == '#'){
            continue;
        }
        printf("Rezultat postfix izraza %s: %.2f\n", line, postfix(line, sizeLine));
    }
    
    free(line);

    return 0;
}

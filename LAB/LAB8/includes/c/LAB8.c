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

int createNode(Node** p_node, float el){
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

float getLastEl(Node* p_head){
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

int isNumCheck(const char* num){
    if(!num){
        return 1;
    }

    int cnt = 0;
    int status = 0;
    while(num[cnt] != '\0') {
        if(!isdigit(num[cnt])) status = 2;
        cnt++;
    }


    return  status;
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

    char* cpy_pf_e = malloc(size + 1);
    if(!cpy_pf_e) return -2;

    memcpy(cpy_pf_e, pf_e, size);
    cpy_pf_e[size] = '\0';
    
    char *saveptr;
    char *word = strtok_r(cpy_pf_e, " \n", &saveptr);
    
    while(word){
        if(!strcmp("+", word)){
            float second = getLastEl(stack);
            pop(stack);
            float first = getLastEl(stack);
            pop(stack);
            push(stack,first + second);
        } else if(!strcmp("-", word)) {
            float second = getLastEl(stack);
            pop(stack);
            float first = getLastEl(stack);
            pop(stack);
            push(stack, first - second);
        } else if (!strcmp("*", word)){
            float second = getLastEl(stack);
            pop(stack);
            float first = getLastEl(stack);
            pop(stack);
            push(stack, first * second);
        } else if(!strcmp("/", word)){
            float second = getLastEl(stack);
            pop(stack);
            float first = getLastEl(stack);
            pop(stack);
            push(stack, first / second);
        } else {
            float val = atof(word);
            push(stack, val);
        }

        word = strtok_r(NULL, " \n", &saveptr);
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

        float res = postfix(line, sizeLine);
        
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;                
        }

        printf("Rezultat postfix izraza %s: %.2f\n", line, res);
    }
    
    free(line);

    return 0;
}

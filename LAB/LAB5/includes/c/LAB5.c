#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../LAB5.h"

int printList(Node* head){
    if(!head || !(head -> next)){
        return -1;
    }

    // Place pointer at start
    Node* nodePointer = head -> next;

    int counter = 0;

    printf("--- LIST START --- \n\n");

    while(nodePointer != NULL){
        printf("%d", nodePointer->num);
        if(nodePointer -> next != NULL) printf(" -> ");
        else printf("\n");


        nodePointer = nodePointer -> next;
        counter++;
    }

    printf("\n ---- LIST END ----\n");

    return 0;
}



int createNode(Node** node, const int num){
    if(!node){
        return -1;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        return -2;
    }

    newNode -> num = num;

    newNode -> next = NULL;

    *node = newNode;

    return 0;
}


int addNodeSorted(Node *head, const int num){
    if(!head){
        return -1;    
    }

    Node* prev = head;
    Node* current = head->next;

    while(current != NULL && current->num <= num){
        prev = current;
        current = current->next;
    }



    Node* newNode = NULL;
    if(createNode(&newNode, num)){
        return -2;
    };

    
    newNode->next = current;
    prev->next = newNode;    



    return 0;
}


int numCheck(char* num){
    if(!num){
        return -1;
    }

    int i = 0;
    while(num[i] != '\0'){
        if(!isdigit(num[i])){
            return -2;
        }
        
        i++;
    }
    return 0;
}

int readFromFile_addToList(FILE* f_list, Node* head){
    if(!f_list || !head){
        return -1;
    }

    size_t sizeLine;
    char* line = NULL;

    while(getline(&line, &sizeLine, f_list) != -1){
        // Jednotavmo comment system
        if(line[0] == '#'){
            continue;
        }
        char* s_num = strtok(line, "\n");

        if(!s_num){
            return -2;
        }

        if(numCheck(s_num)){
            return -3;
        }

        int num = atoi(s_num);

        addNodeSorted(head, num);

    }
    
    free(line);
    return 0;
}

/*
    noRepeat_addNodeSorted

    Ova specijalna verzija addNodeSorted funckije
    samo ne dodaje element u novu lisutu ako on 
    vec postoji
*/
int noRepeat_addNodeSorted(Node *head, const int num){
    if(!head){
        return -1;    
    }

    Node* prev = head;
    Node* current = head->next;


    while(current != NULL && current->num < num){
        prev = current;
        current = current->next;
    }


    // No repeating numbers
    if(current != NULL && current -> num == num){
        return 10;
    }

    Node* newNode = NULL;
    if(createNode(&newNode, num)){
        return -2;
    };

    
    newNode->next = current;
    prev->next = newNode;    



    return 0;
}


int unionOfList(Node** rList, Node* list1, Node* list2){
    if(!rList || !list1 || !list2){
        return -1;
    }

    Node* result = malloc(sizeof(Node));
    if(!result){
        return -2;
    }
    result -> next = NULL;


    Node* p1 = list1 -> next;
    Node* p2 = list2 -> next;


    while(p1 != NULL){
        noRepeat_addNodeSorted(result, p1 -> num);
        p1 = p1 -> next;
    }

    while(p2 != NULL){
        noRepeat_addNodeSorted(result, p2 -> num);
        p2 = p2 -> next;
    }


    *rList = result;

    return 0;
}


int intersectionOfList(Node** rList, Node* list1, Node* list2){
    if(!rList || !list1 || !list2){
        return -1;
    }

    Node* result = malloc(sizeof(Node));
    if(!result){
        return -2;
    }
    result -> next = NULL;


    Node* p1 = list1 -> next;
    Node* p2 = list2 -> next;


    while(p1 != NULL){
        p2 = list2 -> next;
        while(p2 != NULL){
            if(p1 -> num == p2 -> num){
                noRepeat_addNodeSorted(result, p1 -> num);
                break;
            }
            p2 = p2 -> next;
        }
        p1 = p1 -> next;
    }


    *rList = result;

    return 0;
}


void cleanMemory(Node* head){
    Node* toClean;
    
    if(head -> next == NULL){
        return;
    }

    while(head != NULL){
        toClean = head;
        head = head ->next;
        free(toClean);
    }
}
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../LAB4.h"

int printList(Node* head){
    if(!head || !(head -> next)){
        return -1;
    }

    // Place pointer at start
    Node* nodePointer = head -> next;

    int counter = 0;

    printf("--- LIST START --- \n\n");

    while(nodePointer != NULL){
        printf("%dx^%d", nodePointer->num, nodePointer->expo);
        if(nodePointer -> next != NULL) printf(" + ");
        else printf("\n");


        nodePointer = nodePointer -> next;
        counter++;
    }

    printf("\n ---- LIST END ----\n");

    return 0;
}



int createNode(Node** node,const int expo, const int num){
    if(!node){
        return -1;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        return -2;
    }

    newNode -> num = num;
    newNode -> expo = expo;

    newNode -> next = NULL;

    *node = newNode;

    return 0;
}

/*
    Mislim da je ovo jedina koja ce nam trebati
    s obzirom na to da zelim readat iz fajla i dodavat 
    expo tocno di na triba

*/
int addNodeSorted(Node *head,const int expo, const int num){
    if(!head){
        return -1;    
    }

    Node* prev = head;
    Node* current = head->next;

    while(current != NULL && current->expo > expo){
        prev = current;
        current = current->next;
    }


    if (current != NULL && current->expo == expo) {
        current->num += num;
        return 0;
    }

    Node* newNode = NULL;
    if(createNode(&newNode, expo, num)){
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
        char* s_num = strtok(line, " ");
        char* s_expo = strtok(NULL, "\n");

        if(!s_num || !s_expo){
            return -2;
        }

        if(numCheck(s_num) || numCheck(s_expo)){
            return -3;
        }

        int num = atoi(s_num);
        int expo = atoi(s_expo);

        addNodeSorted(head, expo, num);

    }
    
    free(line);
    return 0;
}


int sumListPolinom(Node** rList, Node* list1, Node* list2, int debug){
    if(!rList || !list1 || !list2){
        return -1;
    }
    
    Node *result = (Node*)malloc(sizeof(Node));
    if(!result){
        return -2;
    }
    result -> next = NULL;

    Node *tmpRList = result;
    Node* p1 = list1 -> next;
    Node* p2 = list2 -> next;

    while(p1 != NULL || p2 != NULL){
        if (p2 == NULL || (p1 != NULL && p1->expo > p2->expo)) {
            if(debug) printf("Upisivanje 1\n");
            // Eksponent iz prve liste veći -> prepiši taj čvor
            addNodeSorted(tmpRList, p1->expo, p1->num);
            p1 = p1->next;
        } else if (p1 == NULL || (p2 != NULL && p2->expo > p1->expo)) {
            if(debug) printf("Upisivanje 2\n");
            // Eksponent iz druge liste veći -> prepiši taj čvor
            addNodeSorted(tmpRList, p2->expo, p2->num);
            p2 = p2->next;
        } else {
            if(debug) printf("Upisivanje 3\n");
            // Eksponenti jednaki -> zbroji
            addNodeSorted(tmpRList, p1->expo, p1->num + p2->num);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    
    *rList = result;

    return 0;
}

int multiplyListPolinom(Node** rList, Node* list1, Node* list2){
    if(!rList || !list1 || !list2){
        return -1;
    }
    
    Node *result = (Node*)malloc(sizeof(Node));
    if(!result){
        return -2;
    }
    result -> next = NULL;

    //Node *tmpRList = result;
    Node* p1 = list1 -> next;

    while(p1 != NULL){
        Node* p2 = list2 -> next; 
        while(p2 != NULL){
            int expo = p1->expo + p2 -> expo; 
            int num = p1->num * p2 -> num;


            int found = 0;
            Node* iterator = result -> next;

            while(iterator != NULL){
                if(expo == iterator -> expo){
                    iterator -> num += num;
                    found = 1;
                    break;
                }
                iterator = iterator -> next;
            }             

            if(!found){
                addNodeSorted(result, expo, num);
            }

            p2 = p2->next;
        }
        p1 = p1-> next;
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
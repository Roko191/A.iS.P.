#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* PRECSCI U HEADER I C FAJL!!! */

typedef struct Person {
    char *name;
    char *surname;
    int year;
    struct Person* next;
} Person;


int createNode(Person** node, char *name, char *surname, int year){
    if(!node){
        return -1;
    }

    Person* newNode = (Person*)malloc(sizeof(Person));
    if(!newNode){
        return -2;
    }

    newNode -> name = strdup(name);
    newNode -> surname = strdup(surname);
    newNode -> year = year;

    newNode -> next = NULL;

    *node = newNode;

    return 0;
}

int addNodeAtStart(Person *head, char *name, char *surname, int year){
    if(!head){
        return -1;    
    }

    Person* newNode;
    if(createNode(&newNode, name, surname, year)){
        return -2;
    };

    newNode -> next = head -> next;
    head -> next = newNode;



    return 0;
}


int printList(Person* head){
    if(!head || !(head -> next)){
        return -1;
    }

    // Place pointer at start
    Person* nodePointer = head -> next;

    int counter = 0;

    printf("--- LIST START --- \n\n");

    while(nodePointer != NULL){
        printf("---------NODE %d---------\n", counter);
        printf("Ime: %s \nPrezime: %s \nGodina: %d\n", nodePointer -> name, nodePointer -> surname, nodePointer -> year);
        printf("-------------------------\n");

        printf("\n\n");

        nodePointer = nodePointer -> next;
        counter++;
    }


    printf(" ---- LIST END ----\n");

    return 0;
}


int addNodeAtEnd(Person* head, char *name, char *surname, int year){
    if(!head){
        return -1;
    }

    Person* newNode;
    if(createNode(&newNode, name, surname, year)){
        return -2;
    };


    Person* p_node = head;

    while(p_node ->next != NULL){
        p_node  = p_node -> next;
    }

    p_node ->next = newNode;

    return 0;
}

int findElement(Person* head, char* surname){
    if(!head || !(head -> next)){
        return -1;
    }

    // Place pointer at start
    Person* nodePointer = head -> next;

    int counter = 0;

    printf("--- SEARCH RESULT --- \n\n");

    while(nodePointer != NULL){
        if(!strcmp(surname, nodePointer->surname)){
        printf("---------NODE %d---------\n", counter);
        printf("Ime: %s \nPrezime: %s \nGodina: %d\n", nodePointer -> name, nodePointer -> surname, nodePointer -> year);
        printf("-------------------------\n");

        printf("\n\n");
        }

        nodePointer = nodePointer -> next;
        counter++;
    }


    printf(" ---- END ----\n");

    return 0;
}


int deleteBySurname(Person **head, const char *surname) {
    if (head == NULL || *head == NULL)
        return 1; 
    if (surname == NULL)
        return 2; 

    Person *current = *head;
    Person *previous = NULL;

    while (current != NULL) {
        if (current->surname != NULL && strcmp(current->surname, surname) == 0) {
            if (previous == NULL)
                *head = current->next;
            else
                previous->next = current->next;

            free(current->name);
            free(current->surname);
            free(current);

            return 0; 
        }
        previous = current;
        current = current->next;
    }

    return 2; 
}

void cleanMemory(Person* head){
    Person* toClean; 
    while(head -> next != NULL){
        toClean = head;
        head = head ->next;
        free(toClean->name);
        free(toClean->surname);
        free(toClean);
    }
    free(head->name);
    free(head->surname);
    free(head);

}
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../LAB3.h"

/* PRECSCI U HEADER I C FAJL!!! */

int createNode(Person** node,const char *name,const char *surname, int year){
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

int addNodeAtStart(Person *head,const char *name,const char *surname, int year){
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


int addNodeAtEnd(Person* head, const char *name, const char *surname, int year){
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

int findElement(Person* head, const char* surname){
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


int addAfterSurname(Person **head, const char *surname, const char *addName, const char *addSurname, int year) {
    if (head == NULL || *head == NULL){
        return 1; 
    }
    if (surname == NULL){
        return 2; 
    
    }

    Person *current = *head;

    while (current != NULL) {
        if (current->surname != NULL && strcmp(current->surname, surname) == 0) {
            Person *newNode; createNode(&newNode, addName, addSurname, year);
            newNode->next = current->next;
            current->next = newNode;

            return 0;

        }
        current = current->next;
    }

    return 2; 
}

int addBeforeSurname(Person **head, const char *surname, const char *addName, const char *addSurname, int year){
    if (head == NULL || *head == NULL){
        return 1; 
    }
    if (surname == NULL){
        return 2; 
    
    }

    Person *current = *head;

    while (current->next != NULL) {
        if (current->next->surname != NULL && strcmp(current->next->surname, surname) == 0) {
            Person *newNode; createNode(&newNode, addName, addSurname, year);
            newNode->next = current->next;
            current->next = newNode;

            return 0;
        }
        current = current->next;
    }

    return 2;
}

int sortListBySurname(Person* head){
    if (!head || !head->next) return -1; 

    Person* sorted = NULL; 
    Person* current = head->next;

    // Iteriramo preko origigi cile liste
    while (current != NULL) {
        // Spremamo ostaatk liste (curr na prvom realnom el liste)
        Person* next = current->next; 

        
        // Ako smo na pocetku sortianje (soreted jov uvik na NULL) ili 
        // ako je prvi element u sorted prije po abecedi prezimonom od trenutnog elementa gdje smo
        // u origigi listi dodamo na pocetak lista
        if (sorted == NULL || strcmp(current->surname, sorted->surname) < 0) {   
            current->next = sorted;
            sorted = current;
        } else {
            
            Person* temp = sorted;
            // Krenemo iterirati preko soretd tako da vidimo gdje zelimo staviti to prezime (temp jer zelimo zapamtiti nas pocetak sorteda)
            while (temp->next != NULL && strcmp(temp->next->surname, current->surname) < 0) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next; 
    }

    head->next = sorted;
    return 0;
}


int createListFromFile(FILE* f_list, Person** head){
    if(!f_list || !head){
        return -1;
    }

    Person* tmp = (Person*)malloc(sizeof(Person));
    if(!tmp){
        return -2;
    }

    tmp -> next = NULL;

    size_t sizeLine;
    char* line = NULL;

    while(getline(&line, &sizeLine, f_list) != -1){
        char *name, *surname;
        int year;

        name = strtok(line, " ");
        surname = strtok(NULL, " ");
        year = atoi(strtok(NULL, "\n"));

        Person *newNode;
        createNode(&newNode, name, surname, year);

        Person *curr = tmp -> next;
        Person *prev = tmp;

        while (curr != NULL && strcmp(curr->surname, newNode->surname) < 0) {
            prev = curr;
            curr = curr->next;
        }

        newNode->next = curr;
        prev->next = newNode;
    }

    free(line);
    *head = tmp;

    return 0;
}

int printListToFile(FILE* f_print, Person* head){
    if(!f_print || !head){return -1;}

    fprintf(f_print, "(HEAD) -> ");
    while(head -> next != NULL){

        fprintf(f_print, "%s %s %d -> ", head -> next -> name, head -> next -> surname, head -> next -> year);

        head = head->next;
    }

    fprintf(f_print, "(NULL)\n");


    return 0;
}

void cleanMemory(Person* head){
    Person* toClean;
    
    if(head -> next != NULL){
        return;
    }

    while(head != NULL){
        toClean = head;
        head = head ->next;
        free(toClean->name);
        free(toClean->surname);
        free(toClean);
    }
}
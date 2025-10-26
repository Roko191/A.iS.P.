#include <stdio.h>
#include <stdlib.h>
#include "./includes/LAB2.h"



int main(){
    printf("---- LAB 2 ----\n\n\n");
    

    // Declare test data
    char name[10] = "Roko";
    char surname[10] = "Vukovic";
    
    char name2[10] = "Petra";
    char surname2[10] = "Peric";

    char name3[10] = "Gabriel";
    char surname3[10] = "Kokan";

    // Init linked list
    Person* head = (Person*)malloc(sizeof(Person));
    if(!head){
        printf("Failed allocating head node");
        return -1;
    }

    // Start node test - TEST 1
    printf("TEST 1\n");
    addNodeAtStart(head, name, surname, 1920);
    addNodeAtStart(head, name2, surname2, 1930);
    printList(head);
    printf("\n");

    // End node test - TEST 2
    printf("TEST 2\n");
    addNodeAtEnd(head, name3, surname3, 2005);
    printList(head);
    printf("\n");

    // Find elemennt - TEST 3
    printf("TEST 3\n");
    findElement(head, "Peric");
    printf("\n");

    // Delete at start - TEST 4.1
    printf("TEST 4.1\n");
    deleteBySurname(&head, "Peric");
    printList(head);
    printf("\n");

    // Return deleted node - RECOVERY FROM 4.1
    addNodeAtStart(head, name2, surname2, 1930);


    // Delete at end - TEST 4.2
    printf("TEST 4.2\n");
    deleteBySurname(&head, "Kokan");
    printList(head);
    printf("\n");


    // Return deleted node - RECOVERY FROM 4.3
    addNodeAtEnd(head, name3, surname3, 2005);

    // Delete in middle - TEST 4.3
    printf("TEST 4.3\n");
    deleteBySurname(&head, "Vukovic");
    printList(head);
    printf("\n");

    // Clenup and exit
    cleanMemory(head);
    return 0;

}
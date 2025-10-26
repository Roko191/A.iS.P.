#include <stdio.h>
#include <stdlib.h>

#include "../LAB3.h"

char* createHeapString();

int menu_addToStart(Person *head){
    if(!head){
        return -3;
    }

    printf("(LAB3:Create node) Enter name: ");
    char *l_name = createHeapString();
    
    printf("(LAB3:Create node) Enter surname: ");
    char *l_surname = createHeapString();

    printf("(LAB3:Create node) Enter year: ");
    int l_year = atoi(createHeapString());
    
    if(!l_surname || !l_surname || !l_surname){
        printf("[ERROR] Failed to init data for node creatinon......Exiting\n");
        return -1;
    }


    if(addNodeAtStart(head, l_name, l_surname, l_year)){
        printf("[ERROR] Failed to create node.....Exiting\n");
        return -2;
    }

    return 0;     
}


int menu_addToEnd(Person *head){
    if(!head){
        return -1;
    }

    printf("(LAB3:Create node) Enter name: ");
    char *l_name = createHeapString();
    
    printf("(LAB3:Create node) Enter surname: ");
    char *l_surname = createHeapString();

    printf("(LAB3:Create node) Enter year: ");
    int l_year = atoi(createHeapString());
    
    if(!l_surname || !l_surname || !l_surname){
        printf("[ERROR] Failed to init data for node creatinon......Exiting\n");
        return -1;
    }


    if(addNodeAtEnd(head, l_name, l_surname, l_year)){
        printf("[ERROR] Failed to create node.....Exiting\n");
        return -2;
    }

    return 0;     
}

int menu_addBeforeSurname(Person *head){
    if(!head){
        return -3;
    }

    printf("(LAB3:Lookup) Enter before which you want to add this node: ");
    char *l_f_surname = createHeapString();

    printf("(LAB3:Create node) Enter name: ");
    char *l_name = createHeapString();
    
    printf("(LAB3:Create node) Enter surname: ");
    char *l_surname = createHeapString();

    printf("(LAB3:Create node) Enter year: ");
    int l_year = atoi(createHeapString());
    
    if(!l_surname || !l_surname || !l_surname){
        printf("[ERROR] Failed to init data for node creatinon......Exiting\n");
        return -1;
    }


    if(addBeforeSurname(&head, l_f_surname,l_name, l_surname, l_year)){
        printf("[ERROR] Failed to create node.....Exiting\n");
        return -2;
    }

    return 0;     
}


int menu_addAfterSurname(Person *head){
    if(!head){
        return -3;
    }

    printf("(LAB3:Lookup) Enter before which you want to add this node: ");
    char *l_f_surname = createHeapString();

    printf("(LAB3:Create node) Enter name: ");
    char *l_name = createHeapString();
    
    printf("(LAB3:Create node) Enter surname: ");
    char *l_surname = createHeapString();

    printf("(LAB3:Create node) Enter year: ");
    int l_year = atoi(createHeapString());
    
    if(!l_f_surname || !l_surname || !l_surname || !l_surname){
        printf("[ERROR] Failed to init data for node creatinon......Exiting\n");
        return -1;
    }


    if(addAfterSurname(&head, l_f_surname,l_name, l_surname, l_year)){
        printf("[ERROR] Failed to create node.....Exiting\n");
        return -2;
    }

    return 0;     
}


int menu_deleteBySurname(Person* head){
    if(!head){
        return -3;
    }

    printf("(LAB3:Lookup) Enter surname in node you want to delete: ");
    char *l_f_surname = createHeapString();


    if(!l_f_surname){
        printf("[ERROR] Failed to init data for node deletion......Exiting\n");
        return -1;
    }

    if(deleteBySurname(&head, l_f_surname)){
        printf("[ERROR] Failed to delete node...Exiting");
        return -2;
    }

    return 0;
}


int menu_findElement(Person *head){
    if(!head){
        return -3;
    }
    printf("(LAB3:Lookup) Enter surname which you want to find in list: ");
    char *l_f_surname = createHeapString();

    if(!l_f_surname){
        printf("[ERROR] Failed to init data for node lookup......Exiting\n");
        return -1;
    }

    if(findElement(head, l_f_surname)){
        printf("[ERROR] Failed to find wanted node by surname\n");
        return -2;
    }

    return 0;
}

int menu_sortListBySurname(Person *head){
    if(!head){
        return -3;
    }
    
    if(sortListBySurname(head)){
        printf("[ERROR] Failed to sort list!\n");
        return -2;
    }

    return 0;
}

int runMenu(){
    int state = 0; 

    Person* head = malloc(sizeof(Person));
    if(!head){
        printf("[ERROR] Failed to init list....Exiting\n");
        return -1;
    }

    while(1){
        printf("[MENU] Please select option: \n");
        printf("\t[1] Add node to start of linked list\n");
        printf("\t[2] Add node to end of linked list\n");
        printf("\t[3] Add node before surname\n");
        printf("\t[4] Add node after surname\n");
        printf("\t[5] Delete elemnt by surname\n");
        printf("\t[6] Find element by surname in linked list\n");
        printf("\t[7] Sort list by surname\n");
        printf("\t[9] Print current state of linked list\n");
        printf("\t[10] Exit from program\n");
        printf("(LAB3:Main menu)> ");
        char* c_option = createHeapString();
        if(!c_option){
            printf("[ERROR] Fail to create string on heap....Exiting\n");
            return -2;
        }
        int n_option = atoi(c_option);
        if(n_option == 10){
            return 0;
        }
        switch(n_option){
            case 1:
                state = menu_addToStart(head);
                if(!state) printf("[INFO] Succesfully added element to the start of list\n");
                break;
            case 2:
                state = menu_addToEnd(head);
                if(!state) printf("[INFO] Succesfully added element to the end of list\n");
                break;
            case 3:
                state = menu_addBeforeSurname(head);
                if(!state) printf("[INFO] Succesfully added element before wanted surname\n");
                break;
            case 4:
                state = menu_addAfterSurname(head);
                if(!state) printf("[INFO] Succesfully added element before wanted surname\n");
                break;
            case 5:
                state = menu_deleteBySurname(head);
                if(!state) printf("[INFO] Succesfully deleted wanted node!\n");
                break;
            case 6:
                state = menu_findElement(head);
                if(!state) printf("[INFO] Succesfully found node!\n");
                break;
            case 7:
                state = menu_sortListBySurname(head);
                if(!state) printf("[INFO] Sorted given list!\n");
                break;
            case 9:
                printList(head);
                break;
            default:
                printf("[WARN] Invalid input. Please try again.");
                break;
        }

    }

    return state;
}
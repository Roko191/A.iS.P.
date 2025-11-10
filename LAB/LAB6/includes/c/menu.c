#include <stdio.h>
#include <stdlib.h>


#include "../LAB6.h"

char* createHeapString();

int menu_mainMenuPrint(){
    printf("===MAIN MENU===\n");
    printf("[1] Opreacije s stogom\n");
    printf("[2] Operacije s redom\n");
    printf("[3] Exit program\n");
    printf("Main Menu > ");
    return 0;
}


int menu_stackPrint(){
    printf("=== STACK MENU ===\n");
    printf("[1] Push\n");
    printf("[2] Pop\n");
    printf("[3] Print stack\n");
    printf("[4] Back\n");

    printf("Stack > ");
    
    return 0;
}

int menu_stack(Node* p_stack_head, int p_verbose){
    if(!p_stack_head){
        perror("Error: ");
        return -1;
    }

    while(1){
        menu_stackPrint();
        char* s_select = createHeapString();
        if(!s_select){
            return -1;
        }
        int num_select = atoi(s_select);
        free(s_select);

        switch (num_select) {
            case 1:
                push(p_stack_head, p_verbose);
                break;
            case 2:
                pop(p_stack_head);
                break;
            case 3:
                printList(p_stack_head);
                break;
            case 4:
                return 0;
            default:
                printf("[WARN] Wrong value please try again");
                break;
        }
    }    


    return 0;
}

int runMenu(int p_verbose){ 
    while(1){
        menu_mainMenuPrint();
        char* s_select = createHeapString();
        if(!s_select){
            perror("Faied to create string: ");
            return -1;
        }
        int num_select = atoi(s_select);
        free(s_select);
        switch (num_select) {
            case 1:{
                Node* stack = malloc(sizeof(Node));
                if(!stack){
                    perror("Fail: ");
                    return -2;
                }
                menu_stack(stack, p_verbose);
                free(stack);
                break;
            }    
            case 2:
                return 0;
                break;
            case 3:
                return 0;
                break;
            default: 
                printf("[WARN] Wrong option was selected please try again!");
                break;
        }
    }
    

    return 0;
}
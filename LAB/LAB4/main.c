#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./includes/test.h"
#include "./includes/LAB4.h"

int alloc_test1(Node** rList, FILE** a_f_list1){
    Node* result = (Node*)malloc(sizeof(Node));
    result -> next = NULL; 
    if(!result){
        return -1;
    }

    FILE* f_list = fopen("list.txt", "r");
    if(!f_list){
        return -2;
    }

    *rList = result;
    *a_f_list1 = f_list;
    
    return 0;
}


int alloc_test23(Node** a_list1, Node** a_list2, FILE** a_f_list1, FILE **a_f_list2){
    Node* list = malloc(sizeof(Node));
    if(!list){
        printf("[ERROR] Failed to load init list...Exiting\n");
        return -1;
    }
    list -> next = NULL;

    Node* list2 = malloc(sizeof(Node));
    if(!list2){
        printf("[ERROR] Failed to load init list...Exiting\n");
        return -1;
    }
    list2 -> next = NULL;

    FILE* f_list = fopen("list.txt", "r");
    if(!f_list){
        printf("[ERROR] Failed to open file for read...Exiting\n");
        return -1;
    }

    FILE* f_list2 = fopen("list2.txt", "r");
    if(!f_list2){
        printf("[ERROR] Failed to open file for read...Exiting\n");
        return -1;
    }

    *a_list1 = list;
    *a_list2 = list2;
    *a_f_list1 = f_list;
    *a_f_list2 = f_list2;

    return 0;
}   


int main(int argc, char **argv){
    printf("--- LAB 4 ---\n");
    
    Node* list = NULL; Node* list2 = NULL; Node* r_list = NULL;
    FILE* f_list; FILE* f_list2;

    // Jako ruzan arg handler al radi
    if(argc <= 1){
        printf("[INFO] No args parrsed running all test...Exiting\n");
        return 0;
    }
    else{
        for(int i = 0; i < argc; i++){

            if(!strcmp(argv[i], "-t")){
                if(i+1>=argc){
                    printf("[INFO] Nema definiranog broja pokreni sve....Exiting\n");
                    return 0;
                    //runAll(head);
                } else {

                        int testNum = atoi(argv[i+1]);
                        switch (testNum){
                            case 1: {

                                if(alloc_test1(&r_list, &f_list)){
                                    printf("[ERROR] Failed allocating data for Test 1....Exiting\n");
                                    return -2;
                                }

                                test1(r_list, f_list);
                                break;
                            }
                            case 2: {

                                if(alloc_test23(&list, &list2,&f_list, &f_list2)){
                                    printf("[ERROR] Failed allocating data for Test 2....Exiting\n");
                                    return -2;
                                }
                                test2(list, list2, &r_list, f_list, f_list2);
                                break;
                            }
                            case 3: {

                                if(alloc_test23(&list, &list2,&f_list, &f_list2)){
                                    printf("[ERROR] Failed allocating data for Test 3....Exiting\n");
                                    return -2;
                                }

                                test3(list, list2, &r_list, f_list, f_list2);
                                break;
                            }
                            default:
                                printf("[WARN] Bad test number, please try again and rerun");
                                break;
                        }
                    }
            }

            if(!strcmp(argv[i], "-p")){
                    if(!printList(list)) printf("\n");
                    if(!printList(list2)) printf("\n");
                    printList(r_list);
            }
        }
    }

    if(list) cleanMemory(list);
    if(list2) cleanMemory(list2);
    if(r_list) cleanMemory(r_list);

    if(f_list) fclose(f_list);
    if(f_list2) fclose(f_list2);

    return 0;
}
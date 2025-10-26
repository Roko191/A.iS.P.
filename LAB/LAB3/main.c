#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./includes/LAB3.h"
#include "./includes/test.h"
#include "./includes/menu.h"

int main(int argc, char **argv){
    int statusCode = 0;

    printf("---- LAB 3 ----\n\n");


    // Init linked list -- can be in main since we will be working with this head constatly
    Person* head = (Person*)malloc(sizeof(Person));
    if(!head){
        printf("Failed allocating head node");
        return -1;
    }
    initList(head);

    // Jako ruzan arg handler al radi
    if(argc <= 1){
        printf("[INFO - LAB 3] No args parrsed running all test\n");
        runAll(head);
    }
    else{
        for(int i = 0; i < argc; i++){
            if(!strcmp(argv[i], "-m")){
                printf("[INFO] Menu mode seleted\n");
                return runMenu();
            }
            
            if(!strcmp(argv[i], "-t")){
                if(i+1>=argc){
                    printf("[INFO] Nema definiranog broja pokreni sve\n");
                    runAll(head);
                } else {

                        int testNum = atoi(argv[i+1]);
                        switch (testNum){
                            case 1:
                                test1(head);
                                break;
                            case 2:
                                test2(head);
                                break;
                            case 3:
                                test3(head);
                                break;
                            case 4:
                                test4(head);
                                break;
                            case 5:
                                test5(head);
                                break;
                            case 6:
                                test6(head);
                                break;
                            case 7:
                                test7(head);
                                break;
                            case 8:
                                test8();
                                break;
                            case 9:
                                if(!test9(head)){
                                    printf("[INFO] Succesfully written to file\n");
                                }
                                break;
                            default:
                                printf("[ERROR] Broj izvan ranga broja testova (1-5)\n");
                                statusCode = -1;
                                break;
                        }
                    }
                }

                if(!strcmp(argv[i], "-p")){
                    printList(head);
                }
            }
        }


    
    cleanMemory(head);
    return statusCode;

}
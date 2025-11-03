#include <stdio.h>

#include "../LAB5.h"
#include "../test.h"


int test1(Node* head, FILE* f_list){
    if(!head){
        return -1;
    }
    
    printf("Test 1 - Read from file and init list\n");

    int status = readFromFile_addToList(f_list, head);

    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);

        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);

        return status;    
    }


    printf("🏁 Test status...Done\n");
    printf("✅ Task completion....Sucesfull\n");

    return 0;
}

int test2(Node* list1, Node* list2, Node** rList, FILE* f_list, FILE* f_list2){
    if( !rList || !list1 || !f_list || !f_list2){
        return -1;
    }

    int status = readFromFile_addToList(f_list, list1);

    printf("Test 2 - Union of list\n");

    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);

        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);

        return status;    
    }

    status = readFromFile_addToList(f_list2, list2);

    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);

        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);

        return status;    
    }


    status = unionOfList(rList,  list1,  list2);
    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);
        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);
        return status;    
    }

    printf("🏁 Test status...Done\n");
    printf("✅ Task completion....Sucesfull\n");

    return 0;
}

int test3(Node* list1, Node* list2, Node** rList, FILE* f_list, FILE* f_list2){
    if( !rList || !list1 || !f_list || !f_list2){
        return -1;
    }

    printf("Test 3 - Intersection of list\n");

    int status = readFromFile_addToList(f_list, list1);

    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);

        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);

        return status;    
    }

    status = readFromFile_addToList(f_list2, list2);

    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);

        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);

        return status;    
    }


    status = intersectionOfList(rList,  list1,  list2);
    if(status){
        printf("[ERROR] Unable to read from file and add to list....Error code: %d\n", status);
        printf("🏁 Test status...Done\n");
        printf("❌ Task completion....Fail[%d]", status);
        return status;    
    }

    printf("🏁 Test status...Done\n");
    printf("✅ Task completion....Sucesfull\n");

    return 0;
}
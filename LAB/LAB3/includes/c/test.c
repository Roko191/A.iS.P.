#include "../test.h"
#include <stdio.h>
#include <stdlib.h>


int initList(Person *head){
    addNodeAtStart(head, "Marko", "Mamic", 2004);
    addNodeAtStart(head, "Luka", "Mandaric", 2005);
    addNodeAtStart(head, "Roko", "Nakic", 2005);
    addNodeAtStart(head, "David", "Dukic", 2004);
    addNodeAtEnd(head, "Borna", "Knezovic", 2005);
    addNodeAtEnd(head, "Marko", "Jurisic", 2005);


    return 0;
}

int test1(Person* head){
    if(!head){
        return -1;
    }

    // DATA
    char name[10] = "Roko";
    char surname[10] = "Vukovic";
    
    char name2[10] = "Petra";
    char surname2[10] = "Peric";


    // Start node test - TEST 1
    printf("TEST 1 - Add node at  start \n");
    addNodeAtStart(head, name, surname, 1920);
    addNodeAtStart(head, name2, surname2, 1930);
    printList(head);
    printf("\n");

    return 0;
}

int test2(Person *head){
    if(!head){
        return -1;
    }

    char name3[10] = "Gabriel";
    char surname3[10] = "Kokan";

    // End node test - TEST 2
    printf("TEST 2 - Add node at end \n");
    addNodeAtEnd(head, name3, surname3, 2005);
    printList(head);
    printf("\n");

    return 0;

}


int test3(Person* head){
    if(!head){
        return -1;
    }

    // Find elemennt - TEST 3

    printf("TEST 3 - Find Element\n");
    findElement(head, "Nakic");
    printf("\n");

    return 0;
}


// Subsets of test 4 - NOT TO BE DEFINED IN HEADER
int test4_1(Person* head){
    if(!head){
        return -1;
    }
        
    // Delete at start - TEST 4.1
    printf("TEST 4.1 - Delete at start \n");
    
    initList(head);
    
    deleteBySurname(&head, "Mamic");
    printList(head);
    printf("\n");

    return 0;
}


int test4_2(Person* head){
    if(!head){
        return -1;
    }

    // Delete at end - TEST 4.2
    printf("TEST 4.2 - delete at end\n");
    
    deleteBySurname(&head, "Kokan");
    printList(head);
    printf("\n");

    return 0;
}

int test4_3(Person* head){
    if(!head){
        return -1;
    }

    // Delete in middle - TEST 4.3
    printf("TEST 4.3 - delete in middle\n");


    deleteBySurname(&head, "Vukovic");
    printList(head);
    printf("\n");


    // Add revovery afrter  add after is tested

    return 0;
}

int test4(Person* head){
    if(!head){
        return -1;
    }
    
    test4_1(head);
    test4_2(head);
    test4_3(head);

    return 0;
}

int test5(Person* head){
    if(!head){
        return -1;
    }

    printf("Test 5 - Add after surname\n");
    addAfterSurname(&head, "Jurisic", "Rino", "Majic", 2005);

    return 0;
}

int test6(Person* head){
    if(!head){
        return -1;
    }

    printf("Test 6 - Add before surname\n");
    addBeforeSurname(&head, "Dukic", "Vanja", "Panthy", 1964);

    return 0;
}

int test7(Person* head){
    if(!head) return -1;
    sortListBySurname(head);

    return 0;
}

int test8(){
    Person* fileList = NULL;

    FILE* f_list = fopen("list.txt", "r");
    if(!f_list){return -1;}


    createListFromFile(f_list, &fileList);
    printList(fileList);

    cleanMemory(fileList);
    fclose(f_list);

    return 0;
}

int test9(Person* head){
    FILE *f_list = fopen("printedList.txt", "a");
    if(!f_list){return -1;}

    printListToFile(f_list,  head);
    fclose(f_list);
    
    return 0;
}


int runAll(Person* head){
    if(!head){
        return -1;
    }
   
    test1(head);
    test2(head);
    test3(head);
    test4(head);
    test5(head);
    test6(head);
    test7(head);

    return 0;
}
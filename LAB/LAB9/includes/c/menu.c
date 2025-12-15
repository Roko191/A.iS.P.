// #include <stdio.h>
// #include <stdlib.h>


// #include "../LAB7.h"

// char* createHeapString();

// int menu_mainMenuPrint(){
//     printf("===MAIN MENU===\n");
//     printf("[1] Opreacije s stogom\n");
//     printf("[2] Operacije s redom\n");
//     printf("[3] Operacije s prioritetnim redom\n");
//     printf("[4] Exit program\n");
//     printf("Main Menu > ");
//     return 0;
// }


// int menu_stackPrint(){
//     printf("=== STACK MENU ===\n");
//     printf("[1] Push\n");
//     printf("[2] Pop\n");
//     printf("[3] Print stack\n");
//     printf("[4] Back\n");

//     printf("Stack > ");
    
//     return 0;
// }

// int menu_queuePrint(){
//     printf("=== QUEUE MENU ===\n");
//     printf("[1] Enqueue\n");
//     printf("[2] Dequeue\n");
//     printf("[3] Print Queue\n");
//     printf("[4] Back\n");

//     printf("Queue > ");
    
//     return 0;
// }

// int menu_pqueuePrint(){
//     printf("=== PRIORITY QUEUE MENU ===\n");
//     printf("[1] Enqueue\n");
//     printf("[2] Dequeue\n");
//     printf("[3] Print Queue\n");
//     printf("[4] Back\n");

//     printf("Priority Queue > ");
    
//     return 0;
// }

// int menu_stack_checkSize(int cnt, int size){
//     if(cnt == size){
//         return 1;
//     }


//     return 0;
// };

// int menu_stack(Node* p_stack_head, int p_verbose){
//     if(!p_stack_head){
//         perror("Error: ");
//         return -1;
//     }

//     int size;

//     while(1){
//         printf("Unesi velicinu stoga: \n");
//         char *s_size = createHeapString();
//         size = atoi(s_size);
//         if(!size){
//             printf("Pogresan unos pokusaj ponovno\n");
//         } else break;
//         free(s_size);   
//     }

//     int cnt = 0;

//     while(1){
//         menu_stackPrint();
//         char* s_select = createHeapString();
//         if(!s_select){
//             return -1;
//         }
//         int num_select = atoi(s_select);
//         free(s_select);

//         switch (num_select) {
//             case 1:
//                 if(menu_stack_checkSize(cnt, size)){
//                     printf("[ERROR] Stack je pun\n");
//                 }else{
//                     push(p_stack_head, p_verbose);
//                         cnt++;
//                 }

//                 break;
//             case 2:
//                 pop(p_stack_head);
//                 if(cnt > 0){cnt--;}
//                 break;
//             case 3:
//                 printList(p_stack_head);
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 printf("[WARN] Wrong value please try again");
//                 break;
//         }
//     }    


//     return 0;
// }

// int menu_queue(Node* p_queue_head, int p_verbose){
//     if(!p_queue_head){
//         perror("Error: ");
//         return -1;
//     }

//     while(1){
//         menu_queuePrint();
//         char* s_select = createHeapString();
//         if(!s_select){
//             return -1;
//         }
//         int num_select = atoi(s_select);
//         free(s_select);

//         switch (num_select) {
//             case 1:
//                 enqueue(p_queue_head, p_verbose);
//                 break;
//             case 2:
//                 dequeue(p_queue_head);
//                 break;
//             case 3:
//                 printList(p_queue_head);
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 printf("[WARN] Wrong value please try again");
//                 break;
//         }
//     }    


//     return 0;
// }

// int menu_pqueue(pq_Node* p_queue_head, int p_verbose){
//     if(!p_queue_head){
//         perror("Error: ");
//         return -1;
//     }

//     while(1){
//         menu_pqueuePrint();
//         char* s_select = createHeapString();
//         if(!s_select){
//             return -1;
//         }
//         int num_select = atoi(s_select);
//         free(s_select);

//         switch (num_select) {
//             case 1:
//                 enqueue(p_queue_head, p_verbose);
//                 break;
//             case 2:
//                 dequeue(p_queue_head);
//                 break;
//             case 3:
//                 printList(p_queue_head);
//                 break;
//             case 4:
//                 return 0;
//             default:
//                 printf("[WARN] Wrong value please try again");
//                 break;
//         }
//     }    


//     return 0;
// }


// int runMenu(int p_verbose){ 
//     while(1){
//         menu_mainMenuPrint();
//         char* s_select = createHeapString();
//         if(!s_select){
//             perror("Faied to create string: ");
//             return -1;
//         }
//         int num_select = atoi(s_select);
//         free(s_select);
//         switch (num_select) {
//             case 1:{
//                 Node* stack = malloc(sizeof(Node));
//                 if(!stack){
//                     perror("Fail to alloc stack: ");
//                     return -2;
//                 }
//                 menu_stack(stack, p_verbose);
//                 cleanMemory(stack);
//                 break;
//             }    
//             case 2: {
//                 Node* queue = malloc(sizeof(Node));
//                 if(!queue){
//                     perror("Failed to alloc queue: ");
//                     return -2;
//                 }
//                 menu_queue(queue, p_verbose);
//                 cleanMemory(queue);
//                 break;
//             }
//             case 3: {
//                 pq_Node* queue = malloc(sizeof(pq_Node));
//                 if(!queue){
//                     perror("Failed to alloc priority queue: ");
//                     return -2;
//                 }
//                 menu_pqueue(queue, p_verbose);
//                 cleanMemory(queue);
//                 break;
//             }
//             case 4: {
//                 return 0;
//                 break;
//             }
//             default: 
//                 printf("[WARN] Wrong option was selected please try again!");
//                 break;
//         }
//     }
    

//     return 0;
// }

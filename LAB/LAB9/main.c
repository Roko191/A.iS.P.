#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "./includes/LAB9.h"
//#include "./includes/menu.h"

#define PRINT 1
#define NO_PRINT 0

#define VERBOSE(format, ...) if(verbose){printf("[VERBOSE] " format, __VA__ARGS__);}

void runAll(int32_t num_count, int32_t print){
    // Testni na malim elementima da se vidi da algoritmi rade
    printf("--- N = %d ---\n", num_count);
    int32_t_v* arr;
    createArrayWithRandomNums(num_count, &arr);
    if(print){
        printf("Orginalni:\n");
        printArray(arr);
    }
    
    // Bubble sort
    int32_t_v* bubble;
    uint64_t start = now_ms();
    bubbleSort(arr, &bubble);
    uint64_t end = now_ms();
    if(print){
        printf("Bubble:\n");
        printArray(bubble);
    }
    printf("Bubble sortu je trebalo: %" PRIu64 "milisekundi\n", end - start);

   // Inesertion sort
    int32_t_v* insertion;
    start = now_ms();
    insertionSort(arr, &insertion);
    end = now_ms();
    if(print){
        printf("Insertion:\n");
        printArray(insertion);
    }
    printf("Insertion sortu je trebalo: %" PRIu64 "milisekundi\n", end - start);

    // Exchange sort
    int32_t_v* exchange;
    start = now_ms();
    exchangeSort(arr, &exchange);
    end = now_ms();
    if(print){
        printf("Exchange sort:\n");
        printArray(exchange);
    }
    printf("Exchange sortu je trebalo: %" PRIu64 "milisekundi\n", end - start);

    // Selection sort
    int32_t_v* selection;
    start = now_ms();
    selectionSort(arr, &selection);
    end = now_ms();
    if(print){
        printf("Selection sort:\n");
        printArray(selection);
    }
    printf("Selection sortu je trebalo: %" PRIu64 "milisekundi\n", end - start);
 
    free(bubble->nums);
    free(bubble);
    
    free(insertion->nums);
    free(insertion);

    free(exchange->nums);
    free(exchange);

    free(selection->nums);
    free(selection);
    
    free(arr->nums);
    free(arr);
}


int main(int argc, char ** argv){
    // Set seed for random num    
    int debug = 0;
    int verbose = 0;

    for(int i=0; i < argc; i++){
        if(!strcmp(argv[i], "-g")){
            debug = 1;
            printf("[DEBUG] You are running program in debug mode!\n");
        }
        if(!strcmp(argv[i], "-v")){
            verbose = 1;
            printf("[VERBOSE] Verbose out has been set!\n");
        }
    }

    srand(genSeed(verbose, debug));
    

    printf("=== LAB9 ===\n");
    //printf("%" PRIu64 "\n", now_ms());
    
    for(int i =  10;  i <= 10000; i *= 10){
        if(i == 10) runAll(i, PRINT);
        runAll(i, NO_PRINT);
    }

    return 0;
}

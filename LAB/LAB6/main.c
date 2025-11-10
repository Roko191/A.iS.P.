#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "./includes/LAB6.h"
#include "./includes/menu.h"

#define VERBOSE(msg) if(verbose){printf("[VERBOSE] %s", msg);}


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
    

    printf("=== LAB6 ===\n");
    
    return runMenu(verbose);
}
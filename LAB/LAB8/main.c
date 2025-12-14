#include <stdio.h>
#include <string.h>

#include "./includes/LAB8.h"

char* createHeapString();

int main(int argc, char ** argv){
    printf("=== LAB8 ===\n");
    
    // Basic parser da mozemo otvoriti fajl iz dokumenta
    FILE* postfix_file = NULL;
    for(int i= 0; i < argc; i++){
        if(!strcmp(argv[i], "-f")){
            if(i >= argc){
                printf("[ERROR] Moras unijeti path do fajla\n");
                printf("Unesi path do fajla: ");
                char* path = createHeapString();
                postfix_file = getFile(path);
                if(!postfix_file){
                    printf("[ERROR] Nisam mogao otvoriti datoteku. Provjeri jel postoji!\n");
                }
            } else {
                postfix_file = getFile(argv[i+1]);
                if(!postfix_file){
                    printf("[ERROR] Nisam mogao otvoriti datoteku. Provjeri jel postoji!\n");
                }
            }
        }
    }


    if(!postfix_file){
        printf("[WARN] Nije unijet argument za file path!\n");
        printf("Unesi path do fajla: ");
        char* path = createHeapString();
        postfix_file = getFile(path);
        if(!postfix_file){
            printf("[ERROR] Nisam mogao otvoriti datoteku. Provjeri jel postoji!\n");
        }

    }


    if(readFileAndCalculate(postfix_file)){
        printf("[ERROR] Neuspjesno izvrsavanje postfix izraza\n");
    }

    fclose(postfix_file);

}
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "err.h"

#ifdef _WIN32
#define ENTER 0x0d
#endif

#ifdef __linux__
#define ENTER '\n'
#endif

// Usefull stuff
char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}


void errPrint(int err){
    printf("Error has happend\n");
    return;
}

// Clears stdin
void flushInputBuff(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);    
}


// Array functons
int* createIntArray(int elCnt){
    int* res = malloc(elCnt * sizeof(int));

    if(!res){
        return NULL;
    }

    return res;
}

int fillArray(int *arr, int elCnt){
    if(!arr || elCnt <= 0){
        return ERR_FUNC_ARG_BAD;
    }


    for(int i = 0; i < elCnt; i++){
        int num;
        printf("Unesi broj: ");
        scanf(" %d", &num);

        *(arr + i) = num;
    }


    return 0;
}


int* createAndFillArray(int elCnt){
    if(elCnt < 0){
        return NULL;
    }
    
    int* res = createIntArray(elCnt);

    if(!res){
        return NULL;
    }

    fillArray(res, elCnt);

    return res;
}

int printArray(int *arr, int elCnt){
    if((!arr) || elCnt < 0){
        return ERR_FUNC_ARG_BAD;
    }

    for(int i = 0; i < elCnt; i++){
        printf("%d ", *(arr + i));
    }

    printf("\n");

    return OK;
}

// Matrix functions

/*
*   Name: createMatrix
*   Arguments: int row -> num of rows; int col -> num of cols
*   Retrun: pointer to start of matrix (int *)
*   Desc:
*         Creates int matrix on heap pased on num of
*         rows and cols passed into func. 
*  
*/

int** createMatrix(int row, int col){

    int** matrix = malloc(row * sizeof(int*));

    if(!matrix){
        return NULL;
    }

    for(int i = 0; i < row; i++){
        matrix[i] = malloc(col * sizeof(int));

        if(!matrix[i]){
            return NULL;
        }
    }

    return matrix;
}


// String functons


/*
*   Name: createHeapString
*   Arguments: None
*   Retrun: pointer to start of string (char *)
*   Desc:
*        Ask for user input and creates string on heap 
*        Its exectly the sizeof string + 1 ('\0')
*
*/

char* createHeapString(){ 
    int size = 1;
    int index = 0;

    char ch = 0;

    char *sPoint = malloc(size);

    if(!sPoint){
        return NULL;
    }

    while(1){
        ch = getc(stdin);

        // printf("\n ch: %c", ch);

        if(ch == ENTER || ch == EOF){
            break;
        }

        if(size - 1 <= index){
            size += 1;

            char *temp;

            temp = (char *)realloc(sPoint, size);
            if(!temp){
                free(sPoint);
                return NULL;
            }

            sPoint = temp;
        }

        sPoint[index++] = ch;

    }
    
    sPoint[index] = '\0';

    return sPoint;
}

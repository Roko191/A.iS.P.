#include <stdlib.h>
#include <string.h>
#include "../func.h"

int getStudentDataFromFile(Student*** students, FILE* stream, int* a_size, int* a_biggest){
    if(!stream || !students){
        return ERR_FUNC_ARG_BAD;
    }

    int pCnt = 0;
    int size = 1;

    Student** tmpPersons = malloc(size * sizeof(Student*));
    if(!tmpPersons){
        return ERR_ALLOC_FAIL;
    }

    size_t sizeLine = 0;
    char *line = NULL;

    while(getline(&line, &sizeLine, stream) != -1){
        
        Student* tmpPerson = malloc(sizeof(Student));
        if(!tmpPerson){
            return ERR_ALLOC_FAIL;
        }

        char *name;
        char *surname;
        char *s_points;


        name = strtok(line, " ");
        surname = strtok(NULL, " ");
        s_points = strtok(NULL, "\n");

        tmpPerson -> name = strdup(name);
        tmpPerson -> surname = strdup(surname);
        tmpPerson -> points = atoi(s_points);

        if(atoi(s_points) > *a_biggest){
            *a_biggest = atoi(s_points);
        }

        if(size - 1 <= pCnt){
            size += 1;
            Student** tmp = realloc(tmpPersons, size * sizeof(Student*));
            if(!tmp){
                return ERR_ALLOC_FAIL;
            }
            tmpPersons = tmp;
        }

        tmpPersons[pCnt++] = tmpPerson;

    }

    *a_size = pCnt;
    *students = tmpPersons;

    free(line);
    return OK;
    
}



int printStudentDataToConsole(Student** students, int size, int biggest){
    if(!students){
        return ERR_FUNC_ARG_BAD;
    }

    printf("Najveci ostavreni broj bodova: %d", biggest);

    for(int i = 0; i < size; i++){
        printf("\n-- Informacije o %d studnetu ---\n", i + 1);
        printf("Ime i Prezime: %s %s\n", students[i] -> name, students[i] -> surname);
        printf("Broj bodova: %d\n", students[i] -> points);
        printf("Relativan broj bodova: %.2f\n", ((float)students[i] -> points/biggest)*100);
    }

    return OK;
}
#pragma once

#include <stdio.h>
#include "../../lib/src/err.h"


typedef struct {
    char* name;
    char* surname;
    int points;
} Student;

int getStudentDataFromFile(Student*** students, FILE* stream, int* size, int* biggest);
int printStudentDataToConsole(Student** students, int size, int biggest);

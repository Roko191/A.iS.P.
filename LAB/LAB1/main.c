#include <stdio.h>
#include "./includes/func.h"
#include <stdlib.h>


int main(){
    FILE* f_students = fopen("osobe.txt", "r");
 
    int size;    
    Student** students;
    int biggest;
    

    getStudentDataFromFile(&students, f_students, &size, &biggest);

    //getPointsFromConsole(students, studenstNum);
    printStudentDataToConsole(students, size, biggest);

    for (int i = 0; i < size; i++) {
        free(students[i]); 
    }

    free(students);
    fclose(f_students);

 
    return 0;
}
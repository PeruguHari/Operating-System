#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "employee.dat"

struct Employee {
    int empID;
    char name[50];
    float salary;
};

void addEmployee() {
    FILE *file = fopen(FILENAME, "ab");
    struct Employee emp;
  
    fwrite(&emp, sizeof(struct Employee), 1, file);
    fclose(file);
}

void displayEmployee(int empID) {
    FILE *file = fopen(FILENAME, "rb");
    struct Employee emp;
  
    fclose(file);
}

void modifyEmployee(int empID) {
    FILE *file = fopen(FILENAME, "r+b");
    struct Employee emp;
 
    fclose(file);
}

void deleteEmployee(int empID) {
    FILE *file = fopen(FILENAME, "r+b");
    struct Employee emp;

    fclose(file);
}

int main() {
    return 0;
}


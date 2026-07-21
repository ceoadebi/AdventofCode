#include <stdio.h>
#include <unistd.h>

/*
    - Script must be able to read a txt file. 
    - pass in parameters from said file.  
    - Paremeters:
        direction  
        magnitude
    - range of numbers: [0,99]
    - each time dial lands on 0 count it 
    - dial starts @ 50

*/ 

int main() {
    //read the file 
    FILE* fp = fopen("input.txt", "r");

    // if there is no file 
    if (fp == NULL) {
        perror("open");
        return -1;
    }

    // declare the line variable and allocate 
    // memory for each line
    char line[256];
    
    //testing if line is being read correctly
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}
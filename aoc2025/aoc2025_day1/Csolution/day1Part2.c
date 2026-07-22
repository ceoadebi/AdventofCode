#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

unsigned int rotateDial(int rotationDirection, int currentDialLocation, int rotateHowFar){
    
    
    return ((rotationDirection * rotateHowFar) + currentDialLocation) % 100; 

}

int main() {
    //read the file 
    FILE* fp = fopen("input.txt", "r");
    int timesHitZero = 0;
    int dialLocation = 50;
    int currentDialLocation = dialLocation;
    int rotDir = 1;
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
        //printf("%s direction: %c\n", line, line[0]);
        // get the direction of the turn
        if (line[0] == 'L') {
            rotDir = -1;
        } else if (line[0] == 'R') {
            rotDir = 1;
        } else {
            perror("rotation direction");
            return -1;
        }
        // strip the magnitude from the direction
        char *slicedLine = &line[1];
        char *endptr;
        //printf("%s", slicedLine);
        long magnitude = strtol(slicedLine, &endptr, 10);
        if (magnitude/100 >0) {
            timesHitZero += ceil(magnitude/100);
        }
        // printf("%ld\n", magnitude);
        currentDialLocation = rotateDial(rotDir,currentDialLocation, magnitude);
        printf("the current location of the dial is %d\n", currentDialLocation);
        if (currentDialLocation == 0) {
            timesHitZero++;
        }

        /*if (line[0] == 'L') {
        //  printf("The direction is LEFT.\n");
            printf("Turn the dial LEFT %ld degrees. \n", magnitude);
        }
        if (line[0] == 'R') {
        //  printf("The direction is RIGHT.\n");
            printf("Turn the dial RIGHT %ld degrees. \n", magnitude);
        }
            */
        
    }
    fclose(fp);
    printf("the password is %d\n", timesHitZero);
}



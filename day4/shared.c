#include "shared.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isBlank(char* line){
    int is_blank = true;

    if (!(line[0] == '\n')){
        return false;    
    }  
    return is_blank;
}


int countBlankLines(char *filename){
    char str[80];
    int blankLines = 0;
    int i = 0;
    FILE* file_to_read = fopen(filename,"r");
    while (fgets(str,80, file_to_read) != NULL){
        if (isBlank(str)){
            blankLines++;
        }
        i++;
    }
    return blankLines; 
}

/*char* element_arr[ARRLEN]; // have to hardcode since element_arr[countPassports(file_to_read) doesnt work in static memory*/
char **splitElements(char *filename,int len){
    FILE *file_to_read = fopen(filename, "r");
    char **element_arr = malloc(sizeof(char*)*(len+1));
    char element[500];
    char str[80];
    int i = 0;
    int j = 0;
    
    while(fgets(str,80, file_to_read) != NULL){
        if (!isBlank(str)){
            strcat(element,str);
        }else {
            element_arr[i] = (char*)malloc(sizeof(char) * (strlen(element)+1));
            strcpy(element_arr[i],element);
            memset(element, '\0', sizeof element);
            i++;
        }
        j++;
    }
	fclose(file_to_read);
    return element_arr;
}

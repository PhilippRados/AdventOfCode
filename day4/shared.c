#include "shared.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int isBlank(char* line){
    int is_blank = true;

    if (!(line[0] == '\n')){
        return false;    
    }  
    return is_blank;
}


int countBlankLines(FILE* file_to_read){
    char str[80];
    int blankLines = 0;
    int i = 0;

    while (i < FILELENGTH){
        if (fgets(str,80, file_to_read) && isBlank(str)){
            blankLines++;
        }
        i++;
    }
    return blankLines; 
}


char* element_arr[ARRLEN]; // have to hardcode since element_arr[countPassports(file_to_read) doesnt work in static memory
void splitPassports(FILE* file_to_read){
    char element[500];
    char str[80];
    int i = 0;
    int j = 0;
    
    while(j < FILELENGTH){
        if (fgets(str,80, file_to_read) && !isBlank(str)){
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
}

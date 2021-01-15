#include <stdio.h>
#include <string.h>

#define FILENAME "inputs.txt"

int isBlank(char* line){
    int is_blank = -1;

    if (!(line[0] == '\n')){
        return 0;    
    }  
    return is_blank;
}

int countPassports(FILE* file_to_read){
    char str[80];
    int blankLines = 0;

    while (!feof(file_to_read)){
        if (fgets(str,80, file_to_read) && isBlank(str)){
            blankLines++;
        }
    }
    return blankLines; //returns 287
}


char* splitPassports(FILE* file_to_read){
    char* element_arr[287]; // have to hardcode since element_arr[countPassports(file_to_read) doesnt work in static memory
    char element[] = "";
    char str[80];
    int i = 0;
    
    while(!feof(file_to_read)){
        if (fgets(str,80, file_to_read) && !isBlank(str)){
            strcat(element,str);
            printf("The string is: %s\n",str);
        }else if (isBlank(str)){
            element_arr[i] = element;
            strcpy(element, "");
            /*element = *("");*/
            i++;
        }
    }

	fclose(file_to_read);
    printf("%s\n",element_arr[0]);
	return element_arr[0];
}

void validatePassords(char* data){
    
}


int main(){
    FILE* file_to_read = fopen(FILENAME,"r");

    char* blank_lines = splitPassports(file_to_read);
    /*printf("%d\n",blank_lines);*/
}

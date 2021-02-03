#include "../day4/shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHAPOS (*element_arr & 31) -1

int countUniques(char *element_arr){
	int len = strlen(element_arr);
	int bool_table[26] = {0,};
	int uniques = 0;

	while (*element_arr != '\0'){
		if (*element_arr != '\n' && bool_table[ALPHAPOS] == 0){ // gets alphabet pos of char
			bool_table[ALPHAPOS] = 1;
			uniques++;
		}
		element_arr++;
	}	
	return uniques;
}

int main(){
    FILE* file_to_read = fopen("inputs.txt", "r");
    int len = countBlankLines(file_to_read);
    char** arr = splitElements(file_to_read,len);
	int result = 0;

	for (int j = 0; j < len;j++){
		result += countUniques(arr[j]);
	}
	
	printf("%d\n",result);
	for (int i = 0; i < len;i++){
		free(arr[i]);
	}
	free(arr);

}

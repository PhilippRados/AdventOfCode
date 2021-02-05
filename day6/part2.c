#include "../day4/shared.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHAPOS (*split & 31) -1

int countSplits(char *str){
	int occ = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == '\n'){
				occ++;	
		} 
	}
	return occ;
}

int compareAnswers(char* element){
	int bool_table[26] = {0,};
	int len = countSplits(element);
	char *split = strtok(element,"\n");
	int result = 0;
	int string_len = 0;

	while (split != NULL){
		string_len = strlen(split);
		for (int j = 0;j < string_len;j++){
			bool_table[ALPHAPOS]++;
			split++;
		}  
		split = strtok(NULL,"\n");
	}
	for (int i = 0;i < 26;i++){
		if (bool_table[i] == len){
			result++;
		}
	}
	return result;
}

int main(){
	FILE* file_to_read = fopen("inputs.txt","r");

	int result = 0;
    int len = countBlankLines(file_to_read);
    char** arr = splitElements(file_to_read,len);

	for (int i = 0;i < len; i++){
		result += compareAnswers(arr[i]);
	}

	printf("%d\n",result);
	for (int i = 0; i < len;i++){
		free(arr[i]);
	}
	free(arr);
}

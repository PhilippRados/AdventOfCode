#include "inputs.h"
#include <stdio.h>
#include <string.h>



int valid_passwords_from_indices(char pw[1000][45]){
	unsigned min;
	unsigned max;
	char searched_letter;
	int valids = 0;

	for (int j = 0;j < 1000;j++){
		sscanf(pw[j],"%u-%u %c: \n", &min, &max, &searched_letter);
		int length = strlen(pw[j]);
		char *ptr = strtok(pw[j], " ");
		
		for(int i = 0;i < 2;i++){
			ptr = strtok(NULL, " ");
		}
		if (ptr[min-1] == searched_letter && ptr[max-1] != searched_letter || ptr[min-1] != searched_letter && ptr[max-1] == searched_letter){
			valids++;
		}
	}
	return valids;
}

int main(){
	int valid_pws = valid_passwords_from_indices(inputs);
	printf("%d\n",valid_pws);

}

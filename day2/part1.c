#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "inputs.h"

int valid_pws(char pw[1000][45]){
	unsigned min;
	unsigned max;
	char searched_letter;
	int valids = 0;

	for (int j = 0;j < 1000;j++){
		long length = strlen(pw[j]);
		int occ = -1; //bc when you count go through the whole string you have to neglect the searched_letter-identifier
		sscanf(pw[j],"%u-%u %c: \n", &min, &max, &searched_letter);
		for (int i = 0;i < length;i++){
			if (pw[j][i] == searched_letter){
				occ++;
			}
		}
		if (max >= occ && min <= occ){
			valids++;
		}
	}
	return valids;
}


int main(){
	int valid_passwords = valid_pws(inputs);
	printf("%u\n",valid_passwords);
	
	return 0;
}

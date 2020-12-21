#include <stdio.h>

int * read_ints (const char* filename){
    FILE* file_to_read = fopen(filename,"r");
	int i = 0;
	int k = 0;
	static int input_arr[201];

	while (!feof(file_to_read)){
		fscanf(file_to_read,"%d",&i);
		input_arr[k] = i;
		k++;
	}


	fclose(file_to_read);
	return input_arr;
}


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FILELENGTH 838
#define FILENAME "inputs.txt"

struct seat {
	int row;
	int column;
};

char *ptr;
int bool_table[928];

int getSeatColumn(int lower, int upper){
	while (strlen(ptr) > 2){
		if (*ptr == 'L'){
			upper = (upper + lower) / 2;
		} else if (*ptr == 'R'){
			lower = ((upper + lower) / 2) + 1;
		}
		ptr++;
	}
	return (*ptr++ == 'L') ? lower : upper;
}

int getSeatRow(int lower, int upper){
	while (strlen(ptr) > 5){
		if (*ptr == 'F'){
			upper = (upper + lower) / 2;
		} else if (*ptr == 'B'){
			lower = ((upper + lower) / 2) + 1;
		}
		ptr++;
	}
	return (*ptr++ == 'F') ? lower : upper;
}

int calcMax(struct seat place){
	return place.row * 8 + place.column;
}

int findMissingId(int arr[FILELENGTH-1],int max){
	int min = arr[0];
	printf("%d\n",min);
	for (int i = 0; i < FILELENGTH; i++){
		bool_table[arr[i]] = 1;
	}
	for (;min <= max;min++){
		if(bool_table[min] == 0){ // && bool_table[min-1] && bool_table[min+1]){
			return min;
		}
	}
	return 0;
}

int compare (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int main(){
	char line[12];
	int max; 
	FILE* file_to_read = fopen(FILENAME,"r");
	struct seat place;
	int ids[FILELENGTH];
	int i = 0;

	while ((ptr = fgets(line,12,file_to_read)) != NULL){
		place.row = getSeatRow(0,127);
		place.column = getSeatColumn(0,7);			
		ids[i] = calcMax(place);
		i++;
	}
	qsort(ids,FILELENGTH-1,sizeof(int),compare);
	max = ids[FILELENGTH-2];
	printf("missing ID: %d\n",findMissingId(ids,max));
}

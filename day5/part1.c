#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define FILELENGTH 837
#define FILENAME "inputs.txt"

struct seat {
	int row;
	int column;
};

char *ptr;

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
	while (strlen(ptr) > 4){
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

int main(){
	char line[12];
	int max = 0;
	FILE* file_to_read = fopen(FILENAME,"r");
	struct seat place;

	while ((ptr = fgets(line,12,file_to_read)) != NULL){
		place.row = getSeatRow(0,127);
		place.column = getSeatColumn(0,7);			
		max = (calcMax(place) > max) ? calcMax(place): max;
	}

	printf("max ID: %d\n",max);
}

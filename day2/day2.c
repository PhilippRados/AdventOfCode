#include "stdlib.h";
#include <stdio.h>;
#include <ctype.h>;
#include <string.h>;

int* password_validator(const char pw[2][40]){
	int min;
	int max;
	int result[2];
	char searched_letter;
	
	for (int j = 0;j < 2;j++){
		long length = strlen(pw[j]);
		int occ = 0;
		for (int i = 0;i < length;i++){
			if (pw[j][i] == '-'){
				min = pw[j][i-1] - '0';
				max = pw[j][i+1]- '0';
			}
			if (pw[j][i] == ':'){
				searched_letter = pw[j][i-1];
			}
			if (pw[j][i] == searched_letter){
				occ++;
			}
			result[j] = occ;
		}
	}
	printf("%d\n",result[0]);
	return result;
}


int main(){
	char password_array[2][40] =  {"2-7 a: aaaghd","1-9 c: cccchgda"};
	int *erg = password_validator(password_array);
	printf("first: %d\nsecond: %d\n",erg[0],erg[1]);

	return 0;
}

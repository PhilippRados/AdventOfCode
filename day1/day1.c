#include "loading_inputs.h"

int multiply_2020(int *data){
	int result;
	int first;
	int second;

	for (int i = 0;i < 200;i++){
		first = *(data + i);
		for (int j = 0;j < 200;j++){ // I know n^2 isnt great but I can still improve if i want
			second = *(data + j);
			if ((first + second) == 2020){
				result = first * second;
				i = j = 1000;
				break;
			}
		}
	}
	printf("first:%d\nsecond:%d\n",first,second);
	return result;
}

int main(){
	int *inputs = read_ints("inputs.txt");

	int result = multiply_2020(inputs);
	printf("%d\n",result);
}


// potential improvements to n^2:
// - use sorting algorithm to find number
// - see if there is some kind of map function

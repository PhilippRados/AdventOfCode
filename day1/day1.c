#include "loading_inputs.h"
#include <stdio.h>
#include <time.h>

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

//not really proud of this one but i don't want to sit on this forever
int part2(int *data){
	int first;
	int second;
	int third;
	int result;


	for (int i = 0;i < 200;i++){
		first = *(data + i);
		for (int j = 0;j < 200;j++){ 
			second = *(data + j);
			for (int k = 0; k < 200;k++){
				third = *(data + k);
				if ((first + second + third) == 2020){
					result = first * second * third;
					i = j = k = 1000;
					break;
				}
			}
		}
	}
	printf("first:%d\nsecond:%d\nthird:%d\n",first,second,third);
	return result;
}

int main(){
	int *inputs = read_ints("inputs.txt");
	int result = part2(inputs);
	
	printf("%d\n",result);
}


// potential improvements to n^2:
// - use sorting algorithm to find number (wouldve been easier if it had been a real arry not a pointer)
// - see if there is some kind of map function
// - implement a set to get O(n) retrieval time
// - search from both directions 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FILE_LENGTH 1000

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

bool binsearch(long arr[25],int searched_value){
    int low = 0;
    int high = 25 - 1;

    while (low <= high){
        int mid = (low + high)/2;

        if (arr[mid] == searched_value){
            return true;
        } else {
            if (arr[mid] < searched_value){
                low = mid + 1;
            } else {
                high = mid - 1; 
            }
        }
    }
    return false;
}

bool findSum(long arr[25],int sum){
    int len = 25;
    long searched_val;

    for (int i = 0; i < len; i++){
        if (binsearch(arr,sum - arr[i])){
            return true;
        }
    }
    return false;
}

long findFirstViolation(long *num_arr){
    long sum;
    long sub_arr[25];

    for (int i = 24; i < FILE_LENGTH; i++){
        sum = num_arr[i+1];
        for (int j = 0; j < 25; j++){
            sub_arr[j] = num_arr[i-j];
        }
        qsort(sub_arr,25,sizeof(long),cmpfunc);

        if (!findSum(sub_arr,sum)){
            return num_arr[i+1];
        }
    }
    return -1;
}


int main(){
    long input_arr[FILE_LENGTH];
    long number;
    int i = 0;
    FILE *file_to_read = fopen("./inputs.txt","r");

    while (fscanf(file_to_read,"%lu\n", &number) && i < FILE_LENGTH){
        input_arr[i] = number;
        i++;
    }

    long result = findFirstViolation(input_arr);
    printf("part1: %lu\n",result);
}

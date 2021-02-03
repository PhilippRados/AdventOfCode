#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "shared.h"

#define FILENAME "inputs.txt"

int validatePassports(char **element_arr,int len){
    char *keys[7] = {"byr:","iyr:","eyr:","hgt:", "hcl:", "ecl:", "pid:"};
    int occ = 0;
    int result = 0;

    for (int i = 0; i < len; i++){
        occ = 0;
        for (int j = 0; j < 7; j++){
            if (strstr(element_arr[i], keys[j])){
                occ++;
            } 
        }
        if (occ == 7){
            result++;
        }
    }
    return result;
}


int main(){
    int valid_passports;
    FILE* file_to_read = fopen(FILENAME,"r");
    int arr_len = countBlankLines(file_to_read);
    char **element_arr = splitElements(file_to_read,arr_len);
    valid_passports = validatePassports(element_arr,arr_len);

    printf("Valids: %d\n", valid_passports);
    for (int i = 0; i < arr_len;i++){
        free(element_arr[i]);
    }
    free(element_arr);
}

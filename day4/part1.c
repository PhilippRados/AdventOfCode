#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "shared.h"

#define FILENAME "inputs.txt"

extern char* element_arr[];

int validatePassports(){
    char *keys[7] = {"byr:","iyr:","eyr:","hgt:", "hcl:", "ecl:", "pid:"};
    int occ = 0;
    int result = 0;

    for (int i = 0; i < ARRLEN; i++){
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

    splitPassports(file_to_read);
    valid_passports = validatePassports();

    printf("Valids: %d\n", valid_passports);
}

#include "shared.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "inputs.txt"
extern char* element_arr[];

int validHcl(char* input){
    int valid;

    for (int i = 0; i < strlen(input);i++){
        if (isdigit(input[i] ||((int)input[i] >= 97 && (int)input[i] <= 102))){ // check ascii value if a-f
            valid = -1;
        }
    }
    return (valid) ? -1 :0;
}

//This looks like its violating the DRY principle but I dont think theres a better way of doing this
int validateFields(char* passport, char* field){
    int valid = 0;
    int byr,iyr,eyr,hgt,pid;
    char* hcl,ecl;

    if (strcmp(field,"byr:")){
        sscanf(passport, "byr:%4d", &byr);
        return (byr <= 2002 && byr >= 1920) ? -1 : 0;
    }
    else if (strcmp(field,"iyr:")) {
        sscanf(passport, "iyr:%4d", &iyr);
        return (iyr >= 2010 && iyr <= 2020) ? -1 : 0;

    }
    else if (strcmp(field,"eyr:")) {
        sscanf(passport, "eyr:%4d", &eyr);
        return (eyr >= 2020 && iyr <= 2030) ? -1 :0;
    }
    else if (strcmp(field,"hgt:")){
        if (sscanf(passport, "hgt:%dcm", &hgt)){
            return (hgt >= 150 && hgt <= 193);
        }
        else if(sscanf(passport, "hgt:%din", &hgt)){
            return (hgt >= 59 && hgt <= 76);
        }
        return 0;
    }
    else if (strcmp(field,"hcl:")) {
        sscanf(passport, "hcl:#%6s", hcl);
        return validHcl(hcl);
    }
    else if (strcmp(field,"ecl:")){
        char* eye_colors[] = {"amb","blu","gry","grn","hzl","oth"};
        sscanf(passport,"ecl:%3s",&ecl);

        for (int i = 0; i < 6;i++){
            if (strcmp(eye_colors[i],&ecl)){
                return -1;
            } else {
                return 0;
            }

        }
    }
    else if (strcmp(field,"pid:")){
        //9digit number with leading zeros
        
    }
    return 0;
}


int validatePassports(){
    char *keys[7] = {"byr:","iyr:","eyr:","hgt:", "hcl:", "ecl:", "pid:"};
    int occ = 0;
    int result = 0;

    for (int i = 0; i < ARRLEN; i++){
        occ = 0;
        for (int j = 0; j < 7; j++){
            if (strstr(element_arr[i], keys[j]) && validateFields(element_arr[j],keys[j])){
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

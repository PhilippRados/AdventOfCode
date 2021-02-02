#include "shared.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define FILENAME "inputs.txt"
extern char* element_arr[];


int getnumber(char *passport, char *to_find){
    char *ptr;
    int value = 0;
    if ((ptr = strstr(passport, to_find))){
        value = atoi(ptr + strlen(to_find));
    }
    return value;
}

int validHeight(char *passport,char *field){
    char* ptr = strstr(passport, field);
    ptr += strlen(field);
    int hgt = atoi(ptr);
    char unit[3];
    int i = 0;

    while (isdigit(*++ptr))
        ;
    while (i < 2){
        unit[i] = *ptr++;
        i++;
    }
    if (strstr(unit,"cm")){
        return (hgt >= 150 && hgt <= 193) ? 1 :0;
    }
    else if(strstr(unit,"in")){
        return (hgt >= 59 && hgt <= 76) ? 1 :0;
    }
    return 0;
}

int validPid(char *passport, char *field){
    int len;
    char *ptr = strstr(passport,field);
    ptr += strlen(field);
    char *copy = ptr;

    while (isdigit(*ptr)){
        ptr++;
    }
    len = ptr - copy;
    return (len == 9) ? 1 :0;
}

int validEcl(char* passport, char* field){
    char* eye_colors[] = {"amb","blu","brn","gry","grn","hzl","oth"};
    char *ptr = strstr(passport,field);
    char ecl[4];
    char *p = ecl;
    int i = 0;

    ptr += strlen(field);

    while (i < 3){
        *p++ = *ptr++;
        i++;
    }

    for (int i = 0; i < 7;i++){
        if (strstr(eye_colors[i],ecl)){
            return 1;
        }
    }
    return 0;
}

int validHcl(char *passport, char *field){
    char *ptr = strstr(passport,field);
    int len;
    ptr += strlen(field);

    if (*ptr++ != '#'){
        return 0;
    } 
    char *copy = ptr;
    while (isxdigit(*ptr)){
        ptr++;
    }
    len = ptr - copy;
    return (len == 6) ? 1 :0;
}

//This looks like its violating the DRY principle 
//but I dont think theres a better way of doing this
int validateFields(char* passport, char* field){
    int valid = 0;
    int byr,iyr,eyr,hgt,pid;

    if (strstr(field,"byr:")){
        byr = getnumber(passport, field);
        return (byr <= 2002 && byr >= 1920) ? 1 : 0;
    }
    else if (strstr(field,"iyr:")) {
        iyr = getnumber(passport, field);
        return (iyr >= 2010 && iyr <= 2020) ? 1 : 0;
    }
    else if (strstr(field,"eyr:")) {
        eyr = getnumber(passport, field);
        return (eyr >= 2020 && iyr <= 2030) ? 1 :0;
    }
    else if (strstr(field,"hgt:")){
        return validHeight(passport, field);
    }
    else if (strstr(field,"hcl:")) {
        return validHcl(passport, field);
    }
    else if (strstr(field,"ecl:")){
        return validEcl(passport,field);
    }
    else if (strstr(field,"pid:")){
        return validPid(passport, field);
    }
    return 0;
}


int validatePassports(){
    char *keys[] = {"byr:","iyr:","eyr:","hgt:", "hcl:", "ecl:", "pid:"};
    int occ = 0;
    int result = 0;

    for (int i = 0; i < ARRLEN; i++){
        occ = 0;
        for (int j = 0; j < (sizeof(keys) / sizeof(keys[0])); j++){
            if (strstr(element_arr[i], keys[j]) && validateFields(element_arr[i],keys[j])){
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

    splitElements(file_to_read);
    valid_passports = validatePassports();

    printf("Valids: %d\n", valid_passports);
}

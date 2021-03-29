#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "./inputs.txt"
#define FILE_LENGTH 629

typedef struct operation {
    char* action;
    int visits;
} operation;

int findSecondExecutionAction(operation *element_arr[FILE_LENGTH]){
    int acc = 0;
    char command[4];
    char sign;
    int number;

    for (int i = 0; i < FILE_LENGTH;i++){
        if (element_arr[i]->visits == 0){
            element_arr[i]->visits++;
            sscanf(element_arr[i]->action, "%s %c%d\n", command,&sign,&number);
            if (strcmp(command,"jmp") == 0){
                i += (sign == '+') ? (number-1) : -(number+1); // you have to subtract 1 bc in the next loop 
                                                               // it's increased again which scews the results
            } else if (strcmp(command, "acc") == 0) {
                acc += (sign == '+') ? number : -number;
            }
        } else {
            return acc;
        }
    }
    return acc;
}


int main(){
    FILE *file_to_read = fopen(PATH,"r"); 
    int i = 0;
    char element[10];
    operation* place;
    operation *element_arr[FILE_LENGTH];
    
    while (fgets(element,10,file_to_read) != NULL){
        element_arr[i] = (operation*)malloc(sizeof(operation)+1);
        element_arr[i]->action = (char*)malloc(strlen(element));
        strcpy(element_arr[i]->action,element);
        element_arr[i]->visits = 0;
        i++;
    }

    int result = findSecondExecutionAction(element_arr);
    printf("part1 answer: %d\n",result);

    /*int bu = 4;*/
    /*int uwe = 2;*/
    /*bu += -uwe;*/
    /*printf("%d\n",bu);*/

	fclose(file_to_read);
}

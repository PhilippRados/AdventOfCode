#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "./inputs.txt"
#define FILE_LENGTH 629

typedef struct operation {
    char* action;
    int visits;
} operation;


operation ** copyArray(operation *element_arr[FILE_LENGTH]){
    operation **copied_array = malloc(FILE_LENGTH * sizeof(*element_arr));

    for (int i = 0; i < FILE_LENGTH; i++){
        copied_array[i] = (operation*)malloc(sizeof(operation)+1);
        copied_array[i]->action = (char*)malloc(strlen(element_arr[i]->action));
        strcpy(copied_array[i]->action,element_arr[i]->action);
        copied_array[i]->visits = 0;
    }
    return copied_array;
}

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
            return -1;
        }
    }
    return acc;
}

int part2(operation *element_arr[FILE_LENGTH]){
    char command[4];
    char sign;
    int number;
    int result;
    operation** copy;

    for (int i = 0; i < FILE_LENGTH; i++){
        sscanf(element_arr[i]->action, "%s %c%d\n", command,&sign,&number);
        if(strcmp(command,"jmp") == 0){
            copy = copyArray(element_arr);
            sprintf(copy[i]->action,"nop %c%d\n",sign,number);

            result = findSecondExecutionAction(copy);
            if(result != -1){
                return result;
            }
        } else if(strcmp(command,"nop") == 0){
            copy = copyArray(element_arr);
            sprintf(copy[i]->action,"jmp %c%d\n",sign,number);

            result = findSecondExecutionAction(copy);
            if(result != -1){
                return result;
            }
        }
    }
    return -1;
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

    int result = part2(element_arr);
    printf("part2 answer: %d\n",result);


    /*free(element_arr);*/
	fclose(file_to_read);
}

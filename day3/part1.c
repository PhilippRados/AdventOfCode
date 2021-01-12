#include "inputs.h"
#include <stdio.h>
#include <stdbool.h>

#define HEIGHT 324
#define WIDTH 32

int count_trees(char input[HEIGHT][WIDTH]){
    int row,col,count = 0;
    char path;

    while(row < HEIGHT){
        row += 1;
        col += 3;

        path = input[row][col % 31];
        if (path == '#'){
            count++;
            printf("row:%d col:%d\n",row,col % 31);
        }
    }
    return count;
}

int main(){
    int encountered_trees = count_trees(inputs);
    printf("%d\n",encountered_trees);
}

// for some reason i was pretty  stuck on this one 
// and all my other attempts failed.. so i saw this vid on yt with a slick answer:
// https://www.youtube.com/watch?v=rWXUsiK3Hl4

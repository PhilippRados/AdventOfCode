#include "inputs.h"
#include <stdio.h>

#define HEIGHT 324
#define WIDTH 32

int treesDifferentSlopes(char input[HEIGHT][WIDTH]){
    int slopeCounts[5];
    int result = 1;

    int slopes[5][2] = {
            {1,1},
            {3,1},
            {5,1},
            {7,1},
            {1,2}
    };
    int len = sizeof(slopes)/sizeof(slopes[0]);

    for (int i = 0; i < len;i++){
        char path;
        int treeCount = 0;
        int col,row = 0;

        while (row < HEIGHT){
            col += slopes[i][0];
            row += slopes[i][1];

            path = input[row][col % 31];
            if (path == '#'){
                treeCount++;
            }
        }
        slopeCounts[i] = treeCount;
    }
    printf("slope1: %d\nslope2: %d\nslope3: %d\nslope4: %d\nslope5: %d\n",slopeCounts[0],slopeCounts[1],slopeCounts[2],slopeCounts[3],slopeCounts[4]);
    for (int j = 0; j < len; j++){
        result *= slopeCounts[j];
    }
    return result;
}


int main(){
    int result = treesDifferentSlopes(inputs);
    printf("%d\n",result);
}



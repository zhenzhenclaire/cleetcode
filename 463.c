#include <stdio.h>
#include <stdlib.h>


int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int islandNum = 0;
    int neighborsNum = 0;

    for(int i = 0;i < gridRowSize;i++){
        for(int j = 0;j < gridColSize; j++){
            if(grid[i][j] == 1){
                islandNum++;
                if(j + 1 < gridColSize && grid[i][j+1] == 1) neighborsNum++;  
                if(i + 1 < gridRowSize && grid[i+1][j] == 1)   neighborsNum++;
            }
        }
    }
    return (islandNum * 4 - neighborsNum * 2);
}
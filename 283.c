#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int *nums, int size){
    int s = 0;
    int t = 0;
    int temp = 0;

    while(1){
        if(t == size - 1) break;
        if(s < size - 1){
            while(nums[s] != 0) s++;
        } 
        if(t < size - 1){
            while(nums[t] == 0) t++;
        }     
        temp = nums[s];
        nums[s] = nums[t];
        nums[t] = temp;

        
    }
}

int main(){
    int nums[5] = {0, 1, 0, 3, 12};
    moveZeroes(nums, 5);
    return 0;
}
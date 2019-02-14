#include<stdio.h>
#include<string.h>


typedef int bool;
#define true 1;
#define false 0;

bool circularArrayLoop1(int* nums, int numsSize) {
    if(numsSize == 0 || numsSize == 1)   return false;
    int myarray[numsSize];
    bool isLoop = false;
    int now = 1, i = 0;
    memset(myarray,0,sizeof(int) * numsSize);
    while(1){
        if(myarray[i] != 0 && now - myarray[i] > 1){
            isLoop = true;
            break;
        }
        if(myarray[i] != 0 && now - myarray[i] == 1)   break;
        myarray[i] = now;
        i = i +  nums[i];
       
        if(i >= numsSize){
            i = i - numsSize;
        }
        if(i < 0){
            i = i + numsSize;
        }

        now++;
    }
    return isLoop;
}

int nextIndex(int now, int* nums, int size){
    int next = 0;
    next = now + nums[now];
    if(next >= size){
        next = next - size;
    }
    if(next < 0){
        next = next + size;
    }
    return next;
}

bool circularArrayLoop(int* nums, int numsSize) {
    int slow=0, fast = 0;
    for(int i = 0; i<numsSize;i++){
        slow = i, fast = nextIndex(slow, nums, numsSize);
        while(nums[i] * nums[fast] > 0 && nums[i] * nums[nextIndex(fast, nums, numsSize)] > 0){
            if(slow == fast){
                if(slow == nextIndex(slow, nums, numsSize)) break;
                else    return true;
            }
            else{
                slow = nextIndex(slow, nums, numsSize);
                fast = nextIndex(nextIndex(fast, nums, numsSize),  nums, numsSize);
            }
        }
    }
    return false;
}

int main(){
    int nums[5] = {-2,1,-1,-2,-2};
    int* num = nums;
    circularArrayLoop(num, 5);
    return 0;
}

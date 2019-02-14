#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(int count, int start, int end, char* p){
    if(start == end)    return 0;
    if(end - start == 1){
        if( *(p+end) - *(p+start) ==1)  return 1;
        else    return 0;
    }
    
}

int findSubstringInWraproundString(char* p) {
    int len = strlen(p);
    int count = len;
    int i = 0, j = 0;
    for(i = 0;i < len;i++){
        for(j = i; j < len;j++){
            
        }
    }
}
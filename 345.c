#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isVowel(char ch){
    int is = 0;
    char vowels[10] = {'a','e','i','o','u', 'A','E','I','O','U'};
    int i = 0;
    for(i = 0; i < 10;i++){
        if(ch == vowels[i]){
            is = 1;
        }
    }
    return is;
}

char* reverseVowels(char* s) {
    const char* vowels = "aeiouAEIOU";
    if(*s == '\0')  return s;
    char *start, *end;
    char temp;
    start = s;
    end = s;
    while(*end != '\0')  end++;
    end--;
    while(start <= end){
        if(*start == '\0')  break;
        if(strchr(vowels, *start)){
        while(!strchr(vowels,*end)) end -= 1;
            temp = *end;
            *end = *start;
            *start = temp;
            start++;
            end--;
        }
        else{
            start++;
        }
        
    }
    return s;
}

char* reverseVowels2(char* s) {
    if(*s == '\0')  return s;
    char *start, *end;
    char temp;
    start = s;
    end = s;
    while(*end != '\0')  end++;
    end--;
    while(start <= end){
        if(*start == '\0')  break;
        if(isVowel(*start)){
            while(isVowel(*end) == 0) end -= 1;
            temp = *end;
            *end = *start;
            *start = temp;
            start++;
            end--;
        }
        else{
            start++;
        }
        
    }
    return s;
}

char* reverseVowels1(char* s) {
    if(s == NULL || *s == '\0')  return s;
    char *vowel, *p, *vowelEnd, *pEnd, *r;
    vowelEnd = (char* )malloc(strlen(s));
    memset(vowelEnd, '\0', strlen(vowelEnd) );  
    vowel = vowelEnd;
    pEnd = (char* )malloc(strlen(s));
     memset(pEnd, '\0', strlen(pEnd) );  
    p = pEnd;

    while(*s != '\0'){
        if(!isVowel(*s)){ 
           *pEnd = *s;
            pEnd++;
        }
        else{   
            *vowelEnd = *s;
            vowelEnd++;
            *pEnd = '*';
            pEnd++;
        }
        s++;
    }
    vowelEnd--;

    r = p;
    while(p != pEnd){
       if(*p == '*'){
           *p = *vowelEnd;
           vowelEnd--;
       }
        p++;
    }
    *p = '\0';

    return r;
}

int main(){
    char my[100]="ai";
    char *mystring = my;
    char *result = reverseVowels(mystring);
    while(*result!='\0'){
        printf("%c\n",*result);
        result++;
    }
    return 0;
}
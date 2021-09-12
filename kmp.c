#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void pre_next(char substr[],int *next){
    next[0] = -1;
    int sub_len = strlen(substr);
    int j = -1;
    for (int i = 1; i < sub_len; i++) {
       while(substr[i] != substr[j+1] && j >= 0)
           j = next[j];
       if(substr[i] == substr[j+1])
           j++;
       next[i] = j;
    }
}

void kmp(char str[],char substr[],int next[]){
    int str_len = strlen(str);
    int sub_len = strlen(substr);
    int j = -1;
    for (int i = 0; i < str_len; i++) {
        while(str[i] != substr[j+1] && j >= 0)
            j = next[j];
        if(str[i] == substr[j+1])
            j++;
        if(j == sub_len - 1){
            printf("匹配位置从 %d 到 %d\n",i - j,i);
            j = next[j];
        }
    }
}

int main(int argc, const char *argv[]){
    char str[] = "no!!is this an oppo?no this is an apple.hah."; 
    char substr[] = "is";
    int *next = malloc(strlen(substr) * sizeof(int));
    pre_next(substr,next);
    kmp(str,substr,next);
    return 0;
}
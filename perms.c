#include <stdio.h>

void swap(char array[],int one,int other){
    char temp = array[one];
    array[one] = array[other];
    array[other] = temp;
}

void perms(char array[],int start,int end){
    if (start == end)
       puts(array); 
    else {
        for (int i = start; i <= end; i++){
            swap(array, start, i);
            perms(array, start + 1, end);
            swap(array, start, i);
        }
    }
}

int main(int argc, const char *argv[]) {
    char array[] = "abcde";
    perms(array, 0, 4);
    return 0;
}
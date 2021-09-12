#include <stdio.h>
#include <stdlib.h>

#define MAX 0x800000        //生成随机数的最大值 
#define SHIFT 5             //BITMAP位移
#define MASK 0x1F           //n为2的x次幂,m mod n = m & (n-1)

#define IN_PATH "rand_num.txt"
#define OUT_PATH "sorted_num.txt"

int main(int argc, const char *argv[]) {
    int temp;
    int a[MAX >> SHIFT] = {0};
    char ret;

    FILE *fp_in = fopen(IN_PATH,"r");
    if(fp_in == NULL){
        perror("FILE Open Failed");
        exit(EXIT_FAILURE);
    }
    while(!feof(fp_in)){
        fscanf(fp_in,"%d%c",&temp,&ret);
        a[temp >> SHIFT] |= 1 << (temp & MASK);
    }
    fclose(fp_in);


    FILE *fp_out = fopen(OUT_PATH,"w+");
    if(fp_out == NULL){
        perror("FILE Open Failed");
        exit(1);
    }
    for(int i = 0;i < MAX;i++){
        if(a[i >> SHIFT] & (1 << (i & MASK)))
            fprintf(fp_out,"%d%c",i,'\n');
    }
    fclose(fp_out);
    return 0;
}
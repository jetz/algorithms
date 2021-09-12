#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 0x800000        //生成随机数的最大值
#define SHIFT 5             //BITMAP位移
#define MASK 0x1F           //n为2的x次幂,m mod n = m & (n-1)

#define N 600000            //生成随机数的数目,太大建立数组会段错误

#define PATH "rand_num.txt"

void gen_rand(int n, int *result){
    int i = 0;
    int flags[MAX >> 5]={0};
    srand(time(NULL));
    while(i < N){
        int temp = rand() & (MAX-1);             //生成0~MAX-1范围的随机数
        if(flags[temp >> SHIFT] & (1 << (temp & MASK)))  //去重
            continue;
        else{
            result[i] = temp;
            flags[temp >>SHIFT] |= (1 << (temp & MASK)); //设置标记,为了去重判断
            i++;
        }
    }
}

int main(int argc, const char *argv[]) {
    int rand_nums[N];
    FILE *fp = fopen(PATH,"w+");
    if(fp == NULL){
        perror("Open File Error");
        exit(1);
    }
    gen_rand(N, rand_nums);
    for (int i = 0; i < N; i++)
        fprintf(fp, "%d\n", rand_nums[i]);
    fclose(fp);
    return 0;
}
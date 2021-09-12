#include <stdio.h>

#define INT_LEN 32

static void
dec2bin(int num,int *buf,size_t len){
    int i = len - 1;
    while (num) {
        buf[i--] = num % 2;
        num /= 2;
    }
}

static int 
bin2dec(int *buf){
    int result = 0;
    int exp = 1;
    for(int i = INT_LEN - 1;i >= 0; i--){
        result += buf[i] * exp;
        exp *= 2;
    }
    return result;
}

int
find_uniq(const int *buf, size_t len){

    int plused[INT_LEN] = {0};
    int result[INT_LEN] = {0};

    for (int i = 0; i < len; i++) {
        int tmp[INT_LEN] = {0};
        dec2bin(buf[i],tmp,INT_LEN);
        for (int j = 0; j < INT_LEN;j++)
            plused[j] += tmp[j];
    }
    for(int i = 0; i < INT_LEN; i++){
        if(plused[i] % 3 == 0)
            result[i] = 0;
        else
            result[i] = 1;
    }
    return bin2dec(result);
}

int main(int argc, const char *argv[]) {
    int arr[] = {9,9,1,2,45,1,2,88,34,34,34,45,1,45,2,9};
    /*
     *int buf[INT_LEN] ={0};
     *dec2bin(65535,buf,INT_LEN);
     *for (int i = 0; i < INT_LEN; i++) {
     *    printf("%d",buf[i]);
     *}
     *printf("\n");
     *printf("%d\n",bin2dec(buf));
     */
    printf("%d\n",find_uniq(arr,sizeof(arr)/sizeof(int)));
    return 0;
}

#include <stdio.h>

////////////////////////////////////////////////////////////////
void reverse(int array[],int begin,int end){
    while(begin < end){
        array[begin] ^= array[end];
        array[end] ^= array[begin];
        array[begin] ^= array[end];
        begin++;
        end--;
    }
}

void cycleshift_1(int array[],int len){
    reverse(array,0,len - 1);
    reverse(array,len,9);
    reverse(array,0,9);
}

///////////////////////////////////////////////////////////////
int gcd(int a,int b){
    while(a != b){
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return b;
}

void cycleshift_2(int array[],int len){
    for(int i = 0;i < gcd(10,len);i++){
        int temp = array[i];
        int k = i,j = i + len;
        while(1){
            if(j >= 10)
                j -= 10;
            if(j == i)
                break;
            array[k] = array[j];
            k = j;
            j = j + len;
        }
        array[k] = temp;
    }
}

///////////////////////////////////////////////////////////////
void swap(int array[],int left,int right,int len){
    for(int i = 0;i < len;i++){
        array[left + i] ^= array[right + i];
        array[right + i] ^= array[left + i];
        array[left + i] ^= array[right + i];
    }
}

void cycleshift_3(int array[],int len){
    int left = len,right = 10 - len;//交换双方各自的长度
    while(left != right){
        if(left < right){
            swap(array,len - left,right + len - left,left);
            right -= left;
        }else if(left > right){
            swap(array,len - left,len,right);
            left -= right;
        }
    }
    swap(array,len - left,len,left);
}

///////////////////////////////////////////////////////////////
int main(){
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    /*cycleshift_1(array,6);*/
    cycleshift_2(array,6);
    /*cycleshift_3(array,6);*/
    for(int i = 0;i < 10;i++)
        printf("%d\t",array[i]);
    printf("\n");
    return 0;
}
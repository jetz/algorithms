/**************************************************************************************
 * n为要划分的正整数，m是划分中的最大加数(当m > n时，最大加数为n)，
 * 1. 当n = 1或m = 1时，值为1，可用程序表示为if(n == 1 || m == 1) return 1;
 * 2. 下面看一看m 和 n的关系。它们有三种关系
 *    (1) m > n
 *    在整数划分中实际上最大加数不能大于n，因此在这种情况等价为integer_partition(n, n);
 *    可用程序表示为if(m > n) return integer_partition(n, n);    
 *    (2) m = n
 *    这种情况可用递归表示为integer_partition(n, m - 1) + 1，就是最大加 数为m和小于m的划
 *    分之和，用程序表示为if(m == n) return integer_partition(n, m - 1) + 1;
 *    (3) m < n
 *    这是最一般的情况，在划分的大多数时都是这种情况。设m = 4，那integer_partition(6, 4)
 *    的值是最大加数小于4划分数和整数2的划分数的和。因此，integer_partition(n, m)可表示
 *    为integer_partition(n, m - 1) + integer_partition(n - m, m)
 ***************************************************************************************/

#include <stdio.h>

int integer_partition(int n, int m){
    if (n==1 || m==1)
        return 1;
    else if (n < m)
        return integer_partition(n, n);
    else if (n == m)
        return 1 + integer_partition(n, m - 1);
    else
        return integer_partition(n, m - 1) + integer_partition(n - m, m);
}


int main(int argc, const char *argv[]) {
    printf("%d\n",integer_partition(50, 50)); 
    return 0;
}
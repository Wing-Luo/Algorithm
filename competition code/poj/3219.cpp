//
// Created by wing on 2017/8/15.
// http://acm.hdu.edu.cn/showproblem.php?pid=6130
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
const int maxn = 2 << 31 + 1;
int n,k;
int array[maxn+1][maxn+1];
int getBinomialCoefficients(int n, int k){
    printf("n:%d,k:%d\n",n, k);
    if(n > 0 && (k == 0 || n == k)){
        return 1;
    }
    if(k>n/2){
        k = n-k+1;
    }
    // k是在n的左半边
    for(int i_n = 0;i_n <= n;i_n++){
        for(int i_k = 0; i_k <= k && i_k<=i_n ; i_k++){
            if(i_k == 0 || i_k == i_n){
                array[i_n][i_k] = 1;
            }else{
                array[i_n][i_k] = array[i_n-1][i_k-1] + array[i_n-1][i_k];
                printf("array[%d][%d]:%d,array[%d][%d]:%d,array:%d\n",i_n-1,i_k-1,array[i_n-1][i_k-1],i_n-1, i_k , array[i_n-1][i_k], array[i_n][i_k]);
            }
            printf("i_n:%d,i_k:%d,array:%d\n",i_n, i_k, array[i_n][i_k]);
        }
    }
    return array[n][k];
}
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        printf("%d\n",getBinomialCoefficients(n, k));
    }
    return 1;
}

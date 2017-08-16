//
// Created by wing on 2017/8/15.
// http://acm.hdu.edu.cn/showproblem.php?pid=6130
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
const int maxn =(int) pow(2, 31);
int n,k;
int array[maxn+1][maxn+1];
int getBinomialCoefficients(int n, int k){
    printf("n:%d,k:%d\n",n, k);
    if(n > 0 && (k == 0 || n == k)){
        return 1;
    }
    if(k < n){
        return getBinomialCoefficients(n-1,k-1)+getBinomialCoefficients(n-1,k);
    }
}
int main() {
    while (scanf("%d%d", &n, &k) != EOF) {
        printf("%d\n",getBinomialCoefficients(n, k));
    }
    return 1;
}

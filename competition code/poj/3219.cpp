//
// Created by wing on 2017/8/15.
// http://acm.hdu.edu.cn/showproblem.php?pid=6130
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
typedef long long ll ;
int n,k;
// [from,to] 连乘
int getLucas(int n, int m, int p){
    //printf("n:%d,m:%d,p:%d\n",n, m, p);
    if(m == 0 || n == m){
        return 1;
    }
    if(n < m || n%p < m%p){
        return 0;
    }
    if(m>n/2){
        m = n-m+1;
    }
    return getLucas(n/p,m/p,p)*getLucas(n%p,m%p,p) % p;
}

ll f[2];
void init(int p)
{       //f[n] = n!
    f[0] = 1;
    for (int i=1; i<=p; ++i) f[i] = f[i-1] * i % p;
}
ll pow_mod(ll a, ll x, int p)
{
    ll ret = 1;
    while (x)
    {
        if (x & 1)  ret = ret * a % p;
        a = a * a % p;
        x >>= 1;
    }
    return ret;
}

ll Lucas(ll n, ll k, int p)        //C (n, k) % p
{
    ll ret = 1;
    while (n && k)
    {
        ll nn = n % p, kk = k % p;
        if (nn < kk) return 0;  //inv (f[kk]) = f[kk] ^ (p - 2) % p
        ret = ret * f[nn] * pow_mod (f[kk] * f[nn-kk] % p, p - 2, p) % p;
        n /= p, k /= p;
    }
    return ret;
}
// 1073741824 573741803
int main() {
    //init (2);
    while (scanf("%d%d", &n, &k) != EOF) {
        printf("%d\n",getLucas(n, k, 2));
    }
    return 1;
}

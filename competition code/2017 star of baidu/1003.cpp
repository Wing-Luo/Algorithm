//
// Created by wing on 2017/8/12.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
const int maxn=100000+5;
const int maxm=1000+5;

LL a[maxn],b[maxn];
LL k[maxm],p[maxm];
LL dp[maxm][15];//防御力为j,打出i点伤害以上时所需的最少晶石
LL isDped[maxm][15];
int n,m;
LL max(LL a,LL b)
{
    return a>b?a:b;
}
LL min(LL a,LL b)
{
    return a<b?a:b;
}
void insertSort_0(int arr[], int length)
{
    int i, j, key;
    for (i = 0; i < length; i++){
        key = arr[i];
        for (j = i - 1; j >= 0; j--){
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}
LL  getDp(LL hp,LL defense){
//    printf("hp:%lld,defense:%lld\n",hp,defense);
    if (isDped[hp][defense] == 0) { // 如果为0表示需要计算
        for(int u=0;u<m;u++)//第u个技能
        {
            LL dmg=p[u]-defense;//第u个技能能造成的伤害
            if(dmg<=0)
                continue;
            if(dmg>=hp)
            {
                if(isDped[hp][defense] == 0){
                    dp[hp][defense]=k[u];
                    isDped[hp][defense] = 1;
                }else{
                    dp[hp][defense]=min(getDp(hp,defense),k[u]);
                }
                if(u == m -1){
                    return dp[hp][defense];
                }
            }
            else
            {
                if(isDped[hp][defense] == 0){
                    dp[hp][defense]=1e18;
                    isDped[hp][defense] = 1;
                }
                dp[hp][defense]=min(getDp(hp,defense),getDp(hp-dmg,defense)+k[u]);
                if(u == m -1){
                    return dp[hp][defense];
                }
            }
        }
    }else{
        return dp[hp][defense];
    }

}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
//        printf("n:%d,m:%d\n",n,m);
        LL upB=0/*最高防御*/,upP=0/*最高攻击*/,hp=0;/*最高生命*/
        for(int i=0; i<n; i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
//            printf("a:%lld,b:%lld\n",a[i],b[i]);
            upB=max(upB,b[i]);
            hp=max(hp,a[i]);
        }

        for(int i=0; i<m; i++)
        {
            scanf("%lld%lld",&k[i],&p[i]);
//            printf("k:%lld,p:%lld\n",k[i],p[i]);
            upP=max(upP,p[i]);
        }
        if(upB>=upP)
        {
            printf("-1\n");
            continue;
        }
        mem(dp,0);
        mem(isDped,0);
        /*for(int i=0; i<=10; i++)//防御
        {
            for(int j=1;j<=hp;j++)//造成伤害值
            {
                dp[j][i]=1e18;
                for(int u=0;u<m;u++)//第u个技能
                {
                    LL dmg=p[u]-i;//第u个技能能造成的伤害
                    if(dmg<=0)
                        continue;
                    if(dmg>=j)
                    {
                        dp[j][i]=min(dp[j][i],k[u]);
                    }
                    else
                    {
                        dp[j][i]=min(dp[j][i],dp[j-dmg][i]+k[u]);
                    }
                }
            }
        }*/
        for(int i=0;i<n;i++)
        {
            getDp(a[i],b[i]);
        }
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dp[a[i]][b[i]];
        }
        printf("%lld\n",ans);
    }
}
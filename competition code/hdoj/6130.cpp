//
// Created by wing on 2017/8/15.
// http://acm.hdu.edu.cn/showproblem.php?pid=6130
//


#include <iostream>
const int maxn=1e7+1;
int n;
int a[5];
int kolakoskiList[maxn];
int getKolakoski(int targetIndex){
    if(targetIndex <= 2){
        return targetIndex;
    }
    int currentIndex = 2;
    int nextNumber = 2;
    kolakoskiList[1] = 1;
    kolakoskiList[2] = 2;
    for (int i = 2; i <= targetIndex; ++i) {
        if(kolakoskiList[i] == 1){
            kolakoskiList[currentIndex] = nextNumber;
            nextNumber = nextNumber == 1?2:1;
            currentIndex += 1;
        }else{
            kolakoskiList[currentIndex] = nextNumber;
            kolakoskiList[currentIndex+1] = nextNumber;
            nextNumber = nextNumber == 1?2:1;
            currentIndex += 2;
        }
        if(currentIndex > targetIndex){
            break;
        }
    }
    return kolakoskiList[targetIndex];
}
int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            printf("%d\n",getKolakoski(a[i]));
        }
    }
}

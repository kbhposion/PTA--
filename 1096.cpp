#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int num, maxNum = sqrt(num), first = 0, maxN = 0;
    cin >> num;
    for(int i = 2; i <= maxNum; i++){
        int temp = 1, cnt = 0;
        for(int j = i; j <= maxNum; j++){
            temp *= j;
            if(num % temp != 0)break;
            cnt++;
            if(cnt > maxN){
                first = i;
                maxN = cnt;
            }
        }
    }
    if(first == 0)cout << 1 << endl << num;
    else printf("%d\n", maxN);
    for(int i = 0; i < maxN; i++){
        if(i == 0)printf("%d", first);
        else printf("*%d", first + i);
    }
    return 0;
}
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n == 0 || n == 1)return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)return false;
    return true;
}
int main(){
int msize, n, m, sets[10010] = {0}, a;
    cin >> msize >> n >> m;
    while(!isPrime(msize))
        msize++;
    for(int i = 0; i < n; i++){
        int flag = 0;
        cin >> a;
        for(int j = 0; j <= msize; j++){
            if(sets[(a + j * j) % msize] == 0){
                sets[(a + j * j) % msize ] = a;
                flag = 1;
                break;
            }
        }
        if(!flag)printf("%d cannot be inserted.\n", a);
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        cin >> a;
        for(int j = 0; j <= msize; j++){
            ans++;
            int pos = (a + j * j) % msize;
            if(sets[pos] == 0 || sets[pos] == a)break;
        }
    }
    printf("%.1f", ans * 1.0 / m);
    return 0;
}
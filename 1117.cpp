#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, test[100010];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> test[i];
    sort(test, test+n, greater<int>());
    int i = 0;
    while(test[i] > i+1 && i < n)i++;
    printf("%d", i);
    return 0;
}
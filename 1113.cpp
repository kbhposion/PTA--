#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, sum = 0;
    cin >> n;
    vector<int> test(n);
    for(int i = 0; i < n; i++)
        cin >> test[i];
    sort(test.begin(), test.end());
    for(int i = 0; i < (n/2); i++)
        sum += (test[test.size() - 1 - i] - test[i]);
    if(n % 2 != 0){
        sum += test[n/2];
        printf("1 %d", sum);
    }else printf("0 %d", sum);
    return 0;
}
#include<iostream>
using namespace std;
int main(){
    int n;
    double m, sum = 0;
    cin >> n;
    for(int i = 0; i <= n; i++){
        cin >> m;
        sum = sum + m *(n-i)*(i+1);
    }
    printf("%0.2f", sum);
    return 0;
}
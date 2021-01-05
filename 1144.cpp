#include<iostream>
using namespace std;
int main(){
    int n, check[100010] = {0};
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a > 0 && a < 100010)
            check[a] = 1;    
    }
    for(int i = 1; i <= n + 1; i++){
            if(check[i] == 0){
                printf("%d", i);
                return 0;
            }
        }
    return 0;
}
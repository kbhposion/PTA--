#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        int flag = 1, v[1010];
        for(int j = 1; j <= m; j++){
            cin >> v[j];
            for(int z = 1; z < j; z++){
                if(v[z] == v[j] || abs(v[z] - v[j]) == abs(z - j)){
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag? "YES" : "NO");
    }
    return 0;
}
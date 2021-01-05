#include<iostream>
#include<map>
using namespace std;
int main(){
    int n, m, a, b, t, edge[210][210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edge[a][b] = edge[b][a] = 1;
    }
    for(int i = 1; i <= n; i++)
        edge[i][i] = 1;
    cin >> t;
    for(int i = 0; i < t; i++){
        int check[210], p, flagc = 1, flagcm = 1;
        cin >> p;
        map<int, bool> mp;
        for(int j = 0; j < p; j++){
            cin >> check[j];
            mp[check[j]] = true;
        }
        for(int j = 0; j < p; j++){
            for(int z = j; z < p; z++){
                if(edge[check[j]][check[z]] == 0){
                    flagc = 0;
                }
            }
        }
        for(int j = 1; j <= n; j++){
            int flag = 1;
            if(mp[j] == false){
                for(int z = 0; z < p; z++){
                    if(edge[check[z]][j] == 0)flag = 0;
                }
                if(flag == 1){
                flagcm = 0;
            }
            }
        }
        if(flagc == 1 && flagcm == 1)printf("Yes\n");
        else if(flagc == 1 && flagcm == 0)printf("Not Maximal\n");
        else printf("Not a Clique\n");
    }
    return 0;
} 
#include<iostream>
#include<vector>
using namespace std;
int main(){
     int n, m, edge[1010][1010], t;
     cin >> n >> m;
     for(int i = 0; i < m; i++){
         int a, b;
         cin >> a >> b;
         edge[a][b] = 1;
     }
    cin >> t;
    vector<int> ans;
    for(int i = 0; i < t; i++){
        int visit[1010][1010] = {0}, flag = 0;
        for(int j = 0; j < n; j++){
            int check;
            cin >> check;
            for(int z = 1; z <= n; z++){
                if(edge[z][check] == 1 && visit[z][check] == 0){
                    flag = 1;
                    break;
                }
            }
            for(int z = 1; z <= n; z++){
                if(edge[check][z] == 1)visit[check][z] = 1;//删除后续边
            }
        }
        if(flag == 1)ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size() - 1)printf(" ");
    }
    return 0;
}
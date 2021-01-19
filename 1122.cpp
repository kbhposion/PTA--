#include<iostream>
using namespace std;
int main(){
    int n, m, t, a, b, edge[210][210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edge[a][b] = edge[b][a] = 1;
    }
    cin >> t;
    for(int i = 0; i < t; i++){
        int test[210], visit[210] = {0}, flag = 1, p, exist = 1;
        cin >> p;
        for(int j = 0; j < p; j++){
            cin >> test[j];
            visit[test[j]]++;
            if(j != 0){
                if(edge[test[j]][test[j-1]] == 0)flag = 0;
            }
        }
        for(int j = 1; j <= n; j++)
            if(visit[j] == 0)exist = 0;
        if(test[0] == test[p-1] && exist == 1 && flag == 1 && visit[test[0]] == 2)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
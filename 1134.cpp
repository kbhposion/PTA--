#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n, m, a, b, t, cnt, num;
    vector<int> G[10010];
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(i);
        G[b].push_back(i);
    }
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> cnt;
        vector<int> visit(m, 0);
        for(int j = 0; j < cnt; j++){
            cin >> num;
            for(int z = 0; z < G[num].size(); z++)
                visit[G[num][z]] = 1;
        }
        int flag = 1;
        for(int j = 0; j < m; j++)
            if(visit[j] == 0)flag = 0;
        if(flag == 1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
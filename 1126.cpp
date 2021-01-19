#include<iostream>
#include<vector>
using namespace std;
int visit[510] = {0}, cnt  = 0;
vector<int> edge[510];
void dfs(int index){
    visit[index] = 1;
    cnt++;
    for(int i = 0; i < edge[index].size(); i++){
        if(visit[edge[index][i]] == 0)
            dfs(edge[index][i]); 
    }
}
int main(){
    int n, m, degree[510] = {0}, a, b, even = 0, odd = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(i != 1)printf(" %d", degree[i]);
        else printf("%d", degree[i]);
        if(degree[i] % 2 == 0)even++;
        else odd++;
    }
    cout << endl;
    dfs(1);
    if(even == n && cnt == n)printf("Eulerian");
    else if(odd == 2 && cnt == n)printf("Semi-Eulerian");
    else printf("Non-Eulerian");
}
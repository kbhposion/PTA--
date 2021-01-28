#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int mindepth = 9999999, minnum = 9999999;
vector<int> edge[100010];
void DFS(int v, int depth){
    if(mindepth < depth)return;
    if(edge[v].size() == 0){
        if(depth == mindepth)minnum++;
        else if(depth < mindepth){
            mindepth = depth;
            minnum = 1;  
        }
    }
    for(int i = 0; i < edge[v].size(); i++)
        DFS(edge[v][i], depth+1);
}
int main(){
    int n, t, a;
    double price, rate;
    cin >> n >> price >> rate;
    for(int i = 0; i < n; i++){
        cin >> t;
        for(int j = 0; j < t; j++){
            cin >> a;
            edge[i].push_back(a);
        }
    }
    DFS(0, 0);
    printf("%.4f %d", price * pow(1+rate/100, mindepth), minnum);
    return 0;
}
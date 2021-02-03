#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int maxlevel = 0, cnt = 0;
vector<int> tree[100010];
void dfs(int root, int level){
    if(tree[root].size() == 0){
        if(level == maxlevel)cnt++;
        if(level > maxlevel){
        maxlevel = level;
        cnt = 1;
        }
        return;
    }
    for(int i = 0; i < tree[root].size(); i++)
        dfs(tree[root][i], level+1);
}
int main(){
    int n, a, start;
    double price, rate, sum;
    cin >> n >> price >> rate;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a != -1)tree[a].push_back(i);
        else start = i;
    }
    dfs(start, 0);
    printf("%.2f %d", price * pow((1 + rate/100.0), maxlevel), cnt);
    return 0;
}
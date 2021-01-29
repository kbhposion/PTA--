#include<iostream>
#include<vector>
using namespace std;
int maxlevel = 0, maxnum, book[101] = {0};
vector<int> per[101];
void DFS(int root, int level){
    book[level]++;
    for(int i = 0; i < per[root].size(); i++)
        DFS(per[root][i], level+1);
}
int main(){
    int n, m, a, t, p;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> p >> t;
        for(int j = 0; j < t; j++){
            cin >> a;
            per[p].push_back(a);
        }
    }
    DFS(1, 1);
    for(int i = 1; i < 100; i++){
        if(book[i] > maxnum){
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
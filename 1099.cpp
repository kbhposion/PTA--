#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, cnt, tree[110][2], maxfloor = 0, exist[110] = {0}, start, first = 1;
vector<int> level[101], ans;
void inorder(int root, int floor){
    if(root == -1)return;
    if(tree[root][0] != -1)inorder(tree[root][0], floor+1);
    level[floor].push_back(ans[cnt++]);
    if(floor > maxfloor)maxfloor = floor;
    if(tree[root][1] != -1)inorder(tree[root][1], floor+1);
}
int main(){
    cin >> n;
    ans.resize(n);
    for(int i = 0; i < n; i++){
        cin >> tree[i][0] >> tree[i][1];
        if(tree[i][0] != -1)exist[tree[i][0]] = 1;
        if(tree[i][1] != -1)exist[tree[i][1]] = 1;
    }
    for(start = 0; start < n; start++)
        if(exist[start] == 0)break;
    for(int i = 0; i < n; i++)
        cin >> ans[i];
    sort(ans.begin(), ans.end());
    inorder(start, 0);
    for(int i = 0; i <= maxfloor; i++){
        for(auto it: level[i]){
            if(first == 1){
                printf("%d", it);
                first = 0;
            }else printf(" %d", it);
        }
    }
    return 0;
}
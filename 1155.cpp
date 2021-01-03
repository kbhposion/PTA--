#include<iostream>
#include<vector>
using namespace std;
int tree[10010] = {0}, Min = 1, Max = 1, n;
vector<int>ans;
void dfs(int num, int prenum){
        ans.push_back(tree[num]);
        if((num*2+1) > n && (num*2) > n){
                for(int i = 0; i < ans.size()-1; i++){
                        printf("%d ", ans[i]);
                }
                printf("%d\n", ans[ans.size()-1]);
                ans.pop_back();
                return;
        }
        if((num*2+1) <= n)dfs(num * 2 + 1, num);
        if((num*2) <= n)dfs(num * 2, num);
        ans.pop_back();
}
int main(){
        cin >> n;
        for(int i = 1; i <= n; i++)
                cin >> tree[i];
        dfs(1, 1);
        for(int i = 2; i <= n; i++){
            if(tree[i/2 ] > tree[i])Min = 0;
            if(tree[i/2 ] < tree[i])Max = 0;
        }
        if(Max == 1)printf("Max Heap");
        else if(Min == 1)printf("Min Heap");
        else printf("Not Heap");
        return 0;
}
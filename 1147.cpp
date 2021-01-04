#include<iostream>
#include<vector>
using namespace std;
int n, m;
std::vector<int> ans;
void postorder(int test[], int root){
    if(root * 2 > n && root * 2 + 1 > n){
        ans.push_back(test[root]);
        return;
    }
    if(root * 2 <= n)postorder(test, root * 2);
    if(root * 2 + 1 <= n)postorder(test, root * 2 + 1);
    ans.push_back(test[root]);
}
int main(){
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        int check[1010], isMax = 1, isMin = 1;
        for(int j = 1; j <= n; j++)
            cin >> check[j];
        for(int j = 2; j <= n; j++){
            if(check[j/2] < check[j])isMax = 0;
            if(check[j/2] > check[j])isMin = 0;
        }
        if(isMax == 1)printf("Max Heap\n");
        else if(isMin == 1)printf("Min Heap\n");
        else printf("Not Heap\n");
        ans.clear();
        postorder(check, 1);
        for(int j = 0; j < ans.size(); j++){
            cout << ans[j];
            if(j != ans.size() - 1)printf(" ");
        }
        printf("\n");
    }
    return 0;
}
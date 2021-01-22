#include<iostream>
#include<string>
using namespace std;
int ans[25], test[25][2];
void fill(int root, int pos){
    if(root == -1)return;
    ans[pos] = root;
    fill(test[root][0], pos * 2 + 1);
    fill(test[root][1], pos * 2 + 2); 
}
int main(){
    int n, visit[25] = {0}, root, flag = 1, last; 
    string a, b;
    cin >> n;
    fill(ans, ans +n, -1);
    fill(test[0], test[0] + 50, -1);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a != "-"){
            test[i][0] = stoi(a);
            visit[stoi(a)] = 1;
        }
        if(b != "-"){
            test[i][1] = stoi(b);
            visit[stoi(b)] = 1;
        }
    }
    for(int i = 0; i < n; i++)
        if(visit[i] == 0)root = i;
    fill(root, 0);
    for(int i = 0; i < n; i++)
        if(ans[i] == -1)flag = 0;
    if(flag == 1)printf("YES %d", ans[n-1]);
    else printf("NO %d", root);
}
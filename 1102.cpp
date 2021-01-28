#include<iostream>
#include<queue>
#include<string>
using namespace std;
int tree[15][2], first = 1, exist[15] = {0};
void inorder(int root){
    if(root == -1)return;
    inorder(tree[root][1]);
    if(first == 1){
        first = 0;
        printf("%d", root);
    }else printf(" %d", root);
    inorder(tree[root][0]);
}
int main(){
    int n, index = 0, start, second = 1;
    cin >> n;
    string a, b;
    fill(tree[0], tree[0] + 15*2, -1);
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if(a != "-"){
            tree[i][0] = stoi(a);
            exist[stoi(a)] = 1;
        }else tree[i][0] = -1;
        if(b != "-"){
            tree[i][1] = stoi(b);
            exist[stoi(b)] = 1;
        }else tree[i][1] = -1;
    }
    for(int i = 0; i < n; i++)
        if(exist[i] == 0)start = i;
    queue<int> level;
    level.push(start);
    while (index < n){
        int flood = level.front();
        if(second == 1){
            printf("%d", flood);
            second = 0;
        }else printf(" %d", flood);
        level.pop();
        if(tree[flood][1] != -1)level.push(tree[flood][1]);
        if(tree[flood][0] != -1)level.push(tree[flood][0]);
        index++;
    }
    cout << endl;
    inorder(start);
    return 0;
}
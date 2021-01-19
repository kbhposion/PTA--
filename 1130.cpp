#include<iostream>
#include<string>
using namespace std;
struct node{
    string value;
    int left, right;
}tree[22];
void inorder(int root, int flag){
    if(root == -1)return;
    if(flag != 1 && (tree[root].left != -1 || tree[root].right != -1))printf("(");
    inorder(tree[root].left, 0);
    printf("%s", tree[root].value.c_str());
    inorder(tree[root].right, 0);
    if(flag != 1 && (tree[root].left != -1 || tree[root].right != -1))printf(")");
}
int main(){
    string a;
    int n, b, c, exist[22] = {0}, start;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        tree[i] = {a, b, c};
        if(b != -1)exist[b] = 1;
        if(c != -1)exist[c] = 1;
    }
    for(int i = 1; i <= n; i++)
        if(exist[i] == 0)start = i;
    inorder(start, 1);
    return 0;
}
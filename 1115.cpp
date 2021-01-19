#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node *left, *right;
};
vector<int> level[1010], ans;
node* build(node *root, int n, int deep){
    if(root == NULL){
        root = new node();
        root->left = root->right = NULL;
        root->data = n;
        level[deep].push_back(n);
    }else if(n <= root->data) root->left = build(root->left, n, deep+1);
    else root->right = build(root->right, n, deep+1);
    return root;
}
int main(){
    int n, t;
    cin >> n;
    node *root = NULL;
    for(int i = 0; i < n; i++){
        cin >> t;
        root = build(root, t, 0);
    }
    for(int i = 0; i <= n; i++)
        if(level[i].size() != 0)ans.push_back(level[i].size());
    int a = ans[ans.size() - 1], b= ans[ans.size() - 2];
    printf("%d + %d = %d", a, b, a+b);
    return 0;
}
#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
struct node{
    int value;
    struct node *left, *right;
};
node* buildTree(node *root, int v){
    if(root == NULL){
        root = new node();
        root->value = v;
        root->left = root->right = NULL;
    }else{
        if(abs(v) < abs(root->value))root->left = buildTree(root->left, v);
        if(abs(v) > abs(root->value))root->right = buildTree(root->right, v);
    }
    return root;
}
int flag1, flag2, fb;
void check1(node* root, int state){
    if(root == NULL)return;
//    if(root->value < 0)state = -1;
    if(root->value * state < 0){
        flag1 = 0;
        return;
    }else{
        if(root->value < 0)check1(root->left, 1);
        else check1(root->left, 0);
        if(root->value < 0)check1(root->right, 1);
        else check1(root->right, 0);
    }
}
void check2(node* root, int black){
    if(root == NULL)return;
    if(root->value > 0)black++;
    if(root->left == NULL && root->right == NULL){
        if(fb == 0){
            fb = black;
        }
        else if(black != fb)flag2 = 0;
//        cout << black << endl;
        return;
    }else{
        check2(root->left, black);
        check2(root->right, black);
    }
}
int main(){
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        int arr[31];
        flag1 = flag2 = 1;
        fb = 0;
        node *root = NULL;
        for(int j = 0; j < m; j++){
            cin >> arr[j];
            root = buildTree(root, arr[j]);
        }
        check1(root, 0);
        check2(root, 0);      
//        cout << flag1 << flag2 <<endl;
        if(flag1 == 1 && flag2 == 1 && arr[0] > 0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
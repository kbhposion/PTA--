#include<iostream>
#include<vector>
using namespace std;
int pre[50010], in[50010];
bool flag = false;
void toPost(int pl, int il, int ir){
    if(il > ir || flag == true)return;
    int i;
    for(i = il; i <= ir; i++)
        if(pre[pl] == in[i])break;
    toPost(pl+1, il, i-1);
    toPost(pl+(i - il)+1, i+1, ir);
    if(flag == false){
        printf("%d", in[i]);
        flag = true;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    toPost(0, 0, n-1);
    return 0;
}
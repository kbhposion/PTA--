#include<iostream>
#include<vector>
using namespace std;
int pre[35], post[35], flag = 1;
vector<int> in;
void toInorder(int prel, int prer, int postl, int postr){
    if(prel == prer){
        in.push_back(pre[prel]);
        return;
    }
    int i = prel + 1;
    if(pre[prel] == post[postr]){
        while(pre[i] != post[postr-1] && i <= prer)i++;
        if(i - prel > 1)toInorder(prel+1, i-1, postl, postl + (i - prel - 1) - 1);
        else flag = 0;
        in.push_back(pre[prel]);
        toInorder(i, prer, postl + (i - prel - 1), postr - 1);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    toInorder(0, n-1, 0, n-1);
    printf("%s", flag? "Yes\n" : "No\n");
    for(int i = 0; i < in.size(); i++){
        if(i != 0)printf(" %d", in[i]);
        else printf("%d", in[i]);
    }
    cout << endl;
    return 0;
}
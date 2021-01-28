#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int n, k, p, maxNum = 0;
vector<int> text, ans, temp; 
void init(){
    for(int i = 0; pow(i, p) <= n; i++)
        text.push_back(pow(i, p));
}
void DFS(int sumNow, int a, int tempk, int num){
    if(tempk == k){
        if(sumNow == n && tempk == k && num > maxNum){
            ans = temp;
            maxNum = num;
        }
        return;
    }
    for(int i = a; i >= 1; i--){
        if(tempk+1 <= k && sumNow + text[i] <= n){
            temp[tempk] = i;
            DFS(sumNow + text[i], i, tempk+1, num + i);
        }
    }
}
int main(){
    cin >> n >> k >> p;
    init();
    temp.resize(k);
    DFS(0, text.size()-1, 0, 0);
    if(ans.size() == 0)printf("Impossible");
    else{
        printf("%d =", n);
        for(int i = 0; i < ans.size(); i++)
            if(i == 0)
                printf(" %d^%d", ans[i], p);
                else printf(" + %d^%d", ans[i], p);
    }
    return 0;
}
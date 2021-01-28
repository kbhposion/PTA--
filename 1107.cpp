#include<iostream>
#include<vector>
#include<algorithm>
int father[1010];
int findFather(int x){
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]){
        int z = a;
        father[a] = x;
        a = father[z];
    }
    return x;
}
void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        father[fb] = fa;
}
using namespace std;
int main(){
    int n, t, ans[1010] = {0}, text[1010];
    cin >> n;
    for(int i = 0; i < 1010; i++)
        father[i] = i;
    for(int i = 0; i < n; i++){
        scanf("%d: ", &t);
        int test[1010];
        cin >> test[0];
        text[i] = test[0];
        for(int j = 1; j < t; j++){
            cin >> test[j];
            Union(test[j-1], test[j]);
        }
    }
    for(int i = 0; i < n; i++)
        ans[findFather(text[i])]++;
    vector<int> fin;
    for(int i = 0;i < 1010; i++)
        if(ans[i] != 0)fin.push_back(ans[i]);
    sort(fin.begin(), fin.end(), greater<int>());
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        if(i == 0)printf("%d", fin[i]);
        else printf(" %d", fin[i]);
    return 0;
}
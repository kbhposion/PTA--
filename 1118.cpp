#include<iostream>
#include<set>
#include<vector>
using namespace std;
int father[10010];
int findFather(int x){
    int z = x;
    while(x != father[x])
        x = father[x];
    while(z != father[z]){
        int a = z;
        z = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)father[fa] = fb;
}
int main(){
    int n, a, b, t;
    set<int> num, ans;
    cin >> n;
    for(int i = 0; i < 10010; i++)
        father[i] = i;
        for(int i = 0; i < n; i++){
        cin >> t;
        vector<int> text(t);
        for(int j = 0; j < t; j++){
            cin >> text[j];
            num.insert(text[j]);
            if(j != 0)Union(text[j], text[j-1]);
        }
    }
    cin >> t;
    for(auto it = num.begin(); it != num.end(); it++){
        ans.insert(findFather(*it));
    }
    printf("%d %d\n", ans.size(), num.size());
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        if(findFather(a) == findFather(b))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
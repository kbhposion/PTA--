#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
    int m, n, a, b, p, q, pre[10010], pos[10010];
    map<int, bool> mp;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> pre[i];
        mp[pre[i]] = true;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(mp[a] == false && mp[b] == false){
            printf("ERROR: %d and %d are not found.\n", a, b);
            continue;
        }
        else if(mp[a] == false || mp[b] == false){
            printf("ERROR: %d is not found.\n", mp[a]? b : a);
            continue;
        }
        for(p = 0; p < n; p++){
            if((pre[p] >= a && pre[p] <= b) || (pre[p] <= a && pre[p] >= b))
                break;
        }
        if((pre[p] < a && pre[p] > b) || (pre[p] > a &&pre[p] < b))
            printf("LCA of %d and %d is %d.\n", a, b, pre[p]);
        if(pre[p] == a || pre[p] == b)
            printf("%d is an ancestor of %d.\n", pre[p] == a? a:b, pre[p] == b? a:b);
    }
    return 0; 
}
#include<iostream>
#include<set>
using namespace std;
struct node{
    int value, cnt;
    bool operator < (const node &a)const{
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main(){
    int n, k, a, hashlist[50010] = {0};
    cin >> n >> k;
    set<node> ans;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(i != 0){
            printf("%d:", a);
            int tempcnt = 0;
            for(auto it = ans.begin(); tempcnt < k && it != ans.end(); it++){
                printf(" %d", it->value);
                tempcnt++;
            }
            printf("\n");
        }
        auto it = ans.find(node{a, hashlist[a]});
        if(it != ans.end())ans.erase(it);
        hashlist[a]++;
        ans.insert(node{a, hashlist[a]});
    }
    return 0;
}
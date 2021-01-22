#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct node{
    string name;
    int high;
}per[10010];
bool cmp(node a, node b){
    return a.high == b.high ? a.name < b.name : a.high > b.high;
};
int main(){
    int n, k, num, pos = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> per[i].name >> per[i].high;
    sort(per, per + n, cmp);
    for(int i = 0, num = n; i < k; i++){
        int cnt, flag = -1;
        if(i == 0)
            cnt = n / k + n % k;
        else cnt = n / k;   
        vector<string> ans(cnt);
        for(int j = 0; j < cnt; j++){
            if(j == 0){
                ans[cnt/2] = per[pos].name;
            }
            else {
                ans[cnt/2 + flag] = per[pos].name;
                if(flag < 0)flag = -flag;
                else flag = -(flag + 1);
            }
            pos++;
        } 
        for(int j = 0; j < ans.size(); j++)
            if(j == 0)printf("%s", ans[j].c_str());
            else printf(" %s", ans[j].c_str());
        cout << endl;        
    }
}
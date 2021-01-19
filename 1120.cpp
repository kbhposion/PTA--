#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int n;
    string test[10010];
    set<int> ans;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> test[i];
        int sum = 0;
        for(int j = 0; j < test[i].size(); j++)sum += stoi(test[i].substr(j, 1));
        ans.insert(sum);
    }
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        if(it != ans.begin())printf(" %d", *it);
        else printf("%d", *it);
    }
    return 0;
}
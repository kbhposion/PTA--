#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int n, skip, start;
    cin >> n >> skip >> start;
    string str[1010];
    set<string> ans;
    for(int i = 1; i <= n; i++)
        cin >> str[i];
    for(int i = start; i <= n; ){
        if(ans.find(str[i]) == ans.end()){
            printf("%s\n", str[i].c_str());
            ans.insert(str[i]);
            i += skip;
        }
        else i++;
    }
    if(ans.size() == 0)printf("Keep going...");
    return 0;
}
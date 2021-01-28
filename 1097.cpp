#include<iostream>
#include<vector>
using namespace std;
struct node{
    int id, data, next;
}num[100010];
int main(){
    int n, start, exist[100000] = {0}, a, b, c;
    vector<int>ans, del;
    cin >> start >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        num[a] = {a, b, c};
    }
    for(int index = start; index != -1; index = num[index].next){
        if(exist[abs(num[index].data)] == 0)ans.push_back(num[index].id);
        else del.push_back(num[index].id);
        exist[abs(num[index].data)] = 1;
    }
    for(int i = 0; i < ans.size(); i++)
        if(i != ans.size()-1)printf("%05d %d %05d\n", num[ans[i]].id, num[ans[i]].data, num[ans[i+1]].id);
        else printf("%05d %d -1\n", num[ans[i]].id, num[ans[i]].data);
    for(int i = 0; i < del.size(); i++)
        if(i != del.size()-1)printf("%05d %d %05d\n", num[del[i]].id, num[del[i]].data, num[del[i+1]].id);
        else printf("%05d %d -1\n", num[del[i]].id, num[del[i]].data);
    return 0;
}
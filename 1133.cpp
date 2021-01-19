#include<iostream>
#include<vector>
using namespace std;
struct node{
    int id, value, next;
}text[100010];
int main(){
    int begin, n, index, a, b, c;
    cin >> begin >> n >> index;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        text[a] = node{a, b, c};
    }
    vector<node> origin, ans;
    for(int i = 0; begin != -1; i++){
        origin.push_back(text[begin]);
        begin = text[begin].next;
    }
    for(int i = 0; i < origin.size(); i++)
        if(origin[i].value < 0)ans.push_back(origin[i]);
    for(int i = 0; i < origin.size(); i++)
        if(origin[i].value <= index && origin[i].value >= 0)ans.push_back(origin[i]);
    for(int i = 0; i < origin.size(); i++)
        if(origin[i].value > index)ans.push_back(origin[i]);
    for(int i = 0; i < ans.size(); i++){
        if(i != ans.size()-1)
            printf("%05d %d %05d\n", ans[i].id, ans[i].value, ans[i+1].id);
        else printf("%05d %d -1\n", ans[i].id, ans[i].value);
    }
    return 0;
}
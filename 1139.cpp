#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;
unordered_map<int, bool> arr;
vector<int> v[100010];
struct node{
    int a, b;
};
bool cmp(node t1, node t2){
    if(t1.a == t2.a)return t1.b < t2.b;
    else return t1.a < t2.a;
}
int main(){
    int n, m, t;
    string p, q;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> p >> q;
        arr[abs(stoi(p)) * 10000 + abs(stoi(q))] = arr[abs(stoi(q)) * 10000 + abs(stoi(p))] = true;
        if(p.size() == q.size()){
            v[abs(stoi(p))].push_back(abs(stoi(q)));
            v[abs(stoi(q))].push_back(abs(stoi(p)));
        }
    }
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> p >> q;
        vector<node> ans;
        for(int j = 0; j < v[abs(stoi(p))].size(); j++){
            for(int z = 0; z < v[abs(stoi(q))].size(); z++){                
                if(v[abs(stoi(p))][j] == abs(stoi(q)) || v[abs(stoi(q))][z] == abs(stoi(p)))continue;
                if(arr[v[abs(stoi(p))][j] * 10000 + v[abs(stoi(q))][z]] == true)
                    ans.push_back(node{v[abs(stoi(p))][j], v[abs(stoi(q))][z]});

            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string name;
    int gp, gm, gf, g;
};
bool cmp(node n1, node n2){
    return n1.g != n2.g ? n1.g > n2.g : n1.name < n2.name;
}
int main(){
    int n, m, t, score, cnt = 1;
    string nm;
    vector<node> stu;
    cin >> n >> m >> t;
    map<string, int> exist;
    for(int i = 0; i < n; i++){
        cin >> nm >> score;
        if(score < 200)continue;
        exist[nm] = cnt++;
        stu.push_back(node{nm, score, -1, -1, -1});
    }
    for(int i = 0; i < m; i++){
        cin >> nm >> score;
        if(exist[nm] == 0)continue;
        stu[exist[nm] - 1].gm = score;
    }
    for(int i = 0; i < t; i++){
        cin >> nm >> score;
        if(exist[nm] == 0)continue;
        stu[exist[nm] - 1].gf = score;
        if(stu[exist[nm] - 1].gm > stu[exist[nm] - 1].gf)stu[exist[nm] - 1].g = (int)(stu[exist[nm] - 1].gm * 0.4 + stu[exist[nm] - 1].gf * 0.6 + 0.5);
        else stu[exist[nm] - 1].g = stu[exist[nm] - 1].gf;
    }
    sort(stu.begin(), stu.end(), cmp);
    for(int i = 0; i < stu.size() && stu[i].g >= 60; i++)
        printf("%s %d %d %d %d\n", stu[i].name.c_str(), stu[i].gp, stu[i].gm, stu[i].gf, stu[i]. g);
    return 0;
}
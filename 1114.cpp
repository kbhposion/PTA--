#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int father[10010], estate[10010] = {0}, estateNum[10010] = {0};
set<int> exist;
struct node{
    int id, num;
    double avgNum, avgArea;
};
bool cmp(node a, node b){
    return a.avgArea == b.avgArea? a.id < b.id : a.avgArea > b.avgArea;
}
int findFather(int x){
    int z = x;
    while(x != father[x])
        x = father[x];
    while(z != father[z]){
        int a = z;
        z = father[a];
        father[a] = x;
    }
    return x;
}
void Union(int a, int b){
    exist.insert(a);
    exist.insert(b);
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb)
        if(fa < fb){
            father[fb] = fa;
        }
        else if(fa > fb){
            father[fa] = fb;
        }
}
int main(){
    int n, a, b, c, d, e, f, g;
    cin >> n;
    for(int i = 0; i < 10010; i++)father[i] = i;
    for(int i = 0; i < n; i++){
        int child[6];
        scanf("%d %d %d %d", &a, &b, &c, &d);
        exist.insert(a);
        for(int j = 0; j < d; j++)
            cin >> child[j];
        cin >> e >> f;
        estate[a] += f;
        estateNum[a] += e;
        if(b != -1)Union(a, b);
        if(c != -1)Union(a, c);
        for(int j = 0; j < d; j++){
            Union(a, child[j]);
        }
    }
    set<int> ans;
    node family[10010];
    for(auto it = exist.begin(); it != exist.end(); it++){
        family[findFather(*it)] = {findFather(*it), family[findFather(*it)].num+1, (double)(estateNum[findFather(*it)] += (findFather(*it) == *it) ? 0 : estateNum[*it]) / (family[findFather(*it)].num+1), (double)(estate[findFather(*it)] += (findFather(*it) == *it) ? 0 : estate[*it]) / (family[findFather(*it)].num+1)};
        ans.insert(findFather(*it));
    }
    vector<node> fin;
    for(auto it : ans)fin.push_back(family[it]);
    sort(fin.begin(), fin.end(), cmp);
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        printf("%04d %d %.3f %.3f\n", fin[i].id, fin[i].num, fin[i].avgNum, fin[i].avgArea);
    return 0;
}
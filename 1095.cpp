#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
struct node{
    string id;
    int time, index;
};
bool cmp(node a, node b){
    if(a.id == b.id)return a.time < b.time;
    else return a.id < b.id;
}
bool cmp1(node a, node b){
    return a.time < b.time;
}
int main(){
    int n, m, hour, min, sec, maxtime = 0, nowtime = 0, sum = 0, j = 0;
    cin >> n >> m;
    string index;
    vector<node> input(n), car;
    vector<string> maxId;
    set<string> exist;
    for(int i = 0; i < n; i++){
        cin >> input[i].id;
        scanf("%d:%d:%d", &hour, &min, &sec);
        cin >> index;
        input[i].time = hour*3600 + min*60 + sec;
        if(index == "in")input[i].index = 1;
        else input[i].index = -1;
    }
    sort(input.begin(), input.end(), cmp);
    for(int i = 0; i+1 < input.size()-1; i++){
        if(input[i].id == input[i+1].id && input[i].index == 1 && input[i+1].index == -1){
            car.push_back(input[i]);
            car.push_back(input[i+1]);
        }
    }
    for(int i = 1; i < car.size(); i = i+2){
        if(i == 1)nowtime = 0;
        else if(car[i].id != car[i-2].id)nowtime = 0;
        nowtime = nowtime + car[i].time - car[i-1].time;
        if(nowtime > maxtime){
            maxtime = nowtime;
            maxId.clear();
            maxId.push_back(car[i].id);
        }else if(nowtime == maxtime)maxId.push_back(car[i].id);
    }
    sort(car.begin(), car.end(), cmp1);
    for(int i = 0; i < m; i++){
        scanf("%d:%d:%d", &hour, &min, &sec);
        int temp = hour*3600 + min*60 + sec;
        for(j; j < car.size() && car[j].time <= temp; j++){
            sum += car[j].index;
        }
        printf("%d\n", sum);
    }
    for(int i = 0; i < maxId.size(); i++)
        if(i == 0)printf("%s", maxId[i].c_str());
        else printf(" %s", maxId[i].c_str());
    hour = maxtime / 3600;
    min = maxtime % 3600 / 60;
    sec = maxtime % 60;
    printf(" %02d:%02d:%02d\n", hour, min, sec);
    return 0;
}
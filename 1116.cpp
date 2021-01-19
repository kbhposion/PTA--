#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n == 1 || n == 0)return false;
    for(int i = 2; i*i <= n; i++)
        if(n % i == 0)return false;
    return true;
}
int main(){
    int n, m, visit[10010] = {0}, champion, exist[10010] = {0}, p;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        exist[p] = i + 1;
        if(i == 0)champion = p;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> p;
        if(visit[p] == 1)printf("%04d: Checked\n", p);
        else if(p == champion){
            printf("%04d: Mystery Award\n", p);
            visit[p] = 1;
        }
        else if(exist[p] != 0 && isPrime(exist[p]) == true){
            printf("%04d: Minion\n");
            visit[p] = 1;
        }
        else if(exist[p] != 0){
            printf("%04d: Chocolate\n", p);
            visit[p] = 1;
        }else printf("%04d: Are you kidding?\n", p);
    }
    return 0;
}
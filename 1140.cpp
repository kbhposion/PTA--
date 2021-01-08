#include<iostream>
#include<string>
using namespace std;
int main(){
    int n, s;
    string str;
    cin >> str >> n;
    for(int i = 1; i < n; i++){
        string ans;
        for(int j = 0; j < str.size(); j = s){
            for(s = j; s < str.size() && str[s] == str[j]; s++);
            ans += str[j] + to_string(s-j);
        }
        str = ans;
    }
    cout << str;
    return 0;
}
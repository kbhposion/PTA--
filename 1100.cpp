#include<iostream>
#include<string>
using namespace std;
string marsNum1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string marsNum2[13] = {"-", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
void mars(int n){
    int a = n % 13, b = n / 13;
    if(b == 0)printf("%s", marsNum1[a].c_str());
    else if(a != 0)printf("%s %s", marsNum2[b].c_str(), marsNum1[a].c_str());
    else printf("%s", marsNum2[b].c_str());
}
int findNum(int index, string num){
    for(int i = 0; i < 13; i++){
        if(index == 1){
            if(num == marsNum1[i])return i;
        }else {
            if(num == marsNum2[i])return i;
        }
    }
    return -2;
}
int main(){
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        string str;
        getline(cin, str);
        if(str[0] - '0' <= 9 && str[0] - '0' >= 0)mars(stoi(str));
        else{
            int a = 0, b = 0;
            if(str.size() > 5){
                a = findNum(1, str.substr(4, 3)), b = findNum(2, str.substr(0, 3));
            }else{
                if(findNum(2, str.substr(0, 3)) != -2)b = findNum(2, str.substr(0, 3));
                else if(findNum(1, str.substr(0, 3)) != -2)a = findNum(1, str.substr(0, 3));
            } 
            cout << a + b * 13;
        }
        cout << endl;
    }
    return 0;
}
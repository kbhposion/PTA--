#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++){
        cin >> str;
        int str1 = stoi(str.substr(0, str.size() / 2));
        int str2 = stoi(str.substr(str.size()/2, str.size()/2));
        if(str1 * str2 != 0 && stoi(str) % (str1*str2) == 0)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

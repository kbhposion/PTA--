#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    int countp = 0, countt = 0, sum = 0;
    for(int i = 0; i < str.size(); i++)
        if(str[i] == 'T')countt++;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'P')countp++;
        if(str[i] == 'T')countt--;
        if(str[i] == 'A')sum = (sum + (countp*countt) % 1000000007) % 1000000007;
    }
    cout << sum;
    return 0;
}
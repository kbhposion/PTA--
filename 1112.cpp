#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
int main(){
    int k, cnt = 1;
    cin >> k;
    string str;
    cin >> str;
    map<char, bool> alphabet;
    set<char> printed;
    for(int i = 1; i < str.size(); i++){
        if(str[i] == str[i-1])cnt++;
        else if(cnt % k == 0 && alphabet[str[i-1]] == false){
            alphabet[str[i-1]] = false;
            cnt = 1;
            }
        else if(cnt % k != 0){
            alphabet[str[i-1]] = true;
            cnt = 1;
        }
        else cnt = 1;
        if(i == str.size()-1 && cnt % k == 0 && alphabet[str[i]] != true)alphabet[str[i]] = false;
        else if(i == str.size()-1 && cnt % k != 0)alphabet[str[i]] = true;
    }
    for(int i = 0; i < str.size(); i++){
        if(!alphabet[str[i]] && printed.find(str[i]) == printed.end()){
            printf("%c", str[i]);
            printed.insert(str[i]);
        }
    }
    cout << endl;
    for(int i = 0; i < str.size(); i++){
        if(alphabet[str[i]] == true)printf("%c", str[i]);
        else if(alphabet[str[i]] == false){
            printf("%c", str[i]);
            i += (k - 1);
        }
    }
    return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string add(string s1, string s2) {
    string s = s1;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--) {
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0) s = "1" + s;
    return s;
}
int main(){
    string num;
    cin >> num;
    for(int i = 0; i < 10; i++){
        string  num2 = num;        
        reverse(num2.begin(), num2.end());
        if(num == num2){
            printf("%s is a palindromic number.", num.c_str());
            return 0;
        }
        if(num == num2){
            printf("%s is a palindromic number.", num.c_str());
            return 0;
        }
        printf("%s + %s = ", num.c_str(), num2.c_str());
        num = add(num, num2);
        cout << num << endl;
    }
    printf("Not found in 10 iterations.");
}
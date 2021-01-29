#include<iostream>
#include<string>
using namespace std;
int main(){
    int book[256] = {0}, result = 0;
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        book[a[i]]++;
    for(int i = 0; i < b.size(); i++)
        if(book[b[i]] > 0)book[b[i]]--;
        else result++;
    if(result > 0)printf("No %d", result);
    else printf("Yes %d", a.size() - b.size());
    return 0;
}
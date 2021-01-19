#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> rope(n);
    for(int i = 0; i < n; i++)
        cin >> rope[i];
    sort(rope.begin(), rope.end());
    int result = rope[0];
    for(int i = 1; i < n; i++){
        result = (result + rope[i]) / 2;
    }
    printf("%d", result);
    return 0;
}
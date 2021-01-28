#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n, max = -1;
    cin >> n;
    vector<int> text(n), ans(n), fin;
    for(int i = 0; i < n; i++)
        cin >> text[i];
    ans = text;
    sort(text.begin(), text.end());
    for(int i = 0; i < n; i++){
        if(ans[i] > max)max = ans[i];
        if(ans[i] == text[i] && ans[i] >= max)fin.push_back(ans[i]);
    }
    printf("%d\n", fin.size());
    for(int i = 0; i < fin.size(); i++)
        if(i == 0)printf("%d", fin[i]);
        else printf(" %d", fin[i]);
    cout << endl;
    return 0;
}
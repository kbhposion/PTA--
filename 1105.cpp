#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, row, column, min = 9999999;
    cin >> n;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0 && (n / i - i) < min){
            row = n / i;
            column = i;
        }
    }
    vector<int> test(n);
    for(int i = 0; i < n; i++)
        cin >> test[i];
    sort(test.begin(), test.end(), greater<int>());
    vector<vector<int>> b(row, vector<int>(column));
    int level = 0, m = 0, c = 0;
    for(int cnt = 0; cnt < n; level++){
        for(int j = level; j < column - level && cnt < n; j++, cnt++)
            b[level][j] = test[cnt];
        for(int j = level + 1; j < row - level - 1 && cnt < n; j++, cnt++)
            b[j][column - level - 1] = test[cnt];
        for(int j = column - level - 1; j >= level && cnt < n; j--, cnt++)
            b[row - level - 1][j] = test[cnt];
        for(int j = row - level - 2; j > level && cnt < n; j--, cnt++)
            b[j][level] = test[cnt];
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++)
            if(j == 0)printf("%d", b[i][j]);
            else printf(" %d", b[i][j]);
        cout << endl;
    }
    return 0;
}
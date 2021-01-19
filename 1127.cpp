#include<iostream>
#include<vector>
using namespace std;
vector<int> level[31];
int post[32], in[32];
void toLevel(int il, int ir, int pl, int pr, int floor){
    if(il > ir)return;
    int i = il;
    for( i; i < ir; i++)
        if(in[i] == post[pr])break;
    level[floor].push_back(in[i]);
    toLevel(il, i - 1, pl, pl + (i - il) - 1, floor+1);
    toLevel(i + 1, ir, pl + (i - il), pr - 1, floor+1);
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    toLevel(0, n-1, 0, n-1, 1);
    for(int i = 1; level[i].size() != 0; i++){
        if(i % 2 == 0){
            for(int j = 0; j < level[i].size(); j++){
                if(i == 1 && j == 0)printf("%d", level[i][j]);
                else printf(" %d", level[i][j]);
            }
        }
        else {
            for(int j = level[i].size()-1; j >= 0; j--){
                if(i == 1 && j == 0)printf("%d", level[i][j]);
                else printf(" %d", level[i][j]);
            }
        }
    }
    return 0;
}
#include<iostream>
#include<queue>
using namespace std;
int n, m, l, t, core[1300][130][80], cnt= 0;
bool visit[1300][130][80] = {false};
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
struct node{
    int x, y, z;
};
bool judge(int y, int x, int z){
    if(x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= l)return false;
    if(core[y][x][z] == 0 || visit[y][x][z] == true)return false;
    return true;
}
int bfs(int y, int x, int z){
    queue<node> ans;
    node temp;
    int size = 0;
    ans.push(node{x, y, z});
    visit[y][x][z] = true;
    while(ans.size() != 0){
        temp = ans.front();
        size++;
        ans.pop();
        for(int i = 0; i < 6; i++){
            int tx = temp.x + X[i];
            int ty = temp.y + Y[i];
            int tz = temp.z + Z[i];
            if(judge(ty, tx, tz)){
                visit[ty][tx][tz] = true;
                ans.push(node{tx, ty, tz});
            }
        }
    }
    if(size >= t)return size;
    else return 0;
}
int main(){
    cin >> n >> m >> l >> t;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < n; j++)
            for(int z = 0; z < m; z++)
                cin >> core[j][z][i];
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            for(int p = 0; p < m; p++){
                if(core[j][p][i] == 1 && visit[j][p][i] == false){
                    cnt += bfs(j, p, i);
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
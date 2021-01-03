#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n, m, edge[210][210] = {0}, t, in;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge[a][b] = edge[b][a] = c;
	}
	cin >> t;
	int ans[220] = {0};
	vector<int> sum;
	for(int i = 0; i < t; i++){
		int num, cnt, flag = 0, index = 0, test[210], visit[210] = {0}, sumt = 0;
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			cin >> test[j];
			visit[test[j]] = 1;
			if(j != 0){
				sumt += edge[test[j-1]][test[j]];
				if(edge[test[j-1]][test[j]] == 0)index = 1;
			}
		}
		sum.push_back(sumt);
		for(int j = 1; j <= n; j++){
			if(visit[j] == 0)flag = 1;
		}
		if(index == 0)
			printf("Path %d: %d ", i+1, sumt);
		else printf("Path %d: NA ", i+1);
		if(cnt < (n+1) || flag == 1 || index == 1 || test[0] != test[cnt-1]){
			ans[i] = 1;
			printf("(Not a TS cycle)\n");
		}
		else if(cnt == n+1 && flag == 0 && test[0] == test[cnt-1])printf("(TS simple cycle)\n");
		else if(cnt > n-1 && flag == 0 && test[0] == test[cnt-1])printf("(TS cycle)\n");
	}
	int min = 99999, z, numM;
	for(z = 0; z < sum.size(); z++){
		if(sum[z] < min && ans[z] != 1){
			min = sum[z];
			numM = z;
		}
	}
	printf("Shortest Dist(%d) = %d", numM+1, sum[numM]);
	return 0;
}

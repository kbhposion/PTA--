#include<iostream>
#include<set>
using namespace std;
int main(){
	int n, m, t, edges[10010][2] = {0};
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> edges[i][0] >> edges[i][1];
	cin >> t;
	for(int i = 0; i < t; i++){
		int test[10010], flag = 0;
		set<int> ans;
		for(int j = 0; j < n; j++){
			cin >> test[j];
			ans.insert(test[j]);
		}
		for(int j = 0; j < m; j++){
			if(test[edges[j][0]] == test[edges[j][1]])
				flag = 1;
		}
		if(flag == 0)
			printf("%d-coloring\n", ans.size());
		else cout << "No\n";
	}
	return 0;
}

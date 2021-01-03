#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main(){
	int n, m;
	map<int, vector<int>> edge;
	cin >> n >> m;
	 for(int i = 0; i < n; i++){
	 	int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	 }
	 for(int i = 0; i < m; i++){
	 	int p, test[1010], index = 0, a[100100] = {0};
		cin >> p;
		for(int j = 0; j < p; j++){
			cin >> test[j];
			a[test[j]] = 1;
		}
		for(int j = 0; j < p; j++){
			for(int z = 0; z < edge[test[j]].size(); z++){
				if(a[edge[test[j]][z]] == 1)index = 1;
			}
		}
		if(index == 1)cout << "No\n";
		else cout << "Yes\n";
	 }
	 return 0;
}

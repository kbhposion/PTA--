#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int n, check[110];
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> check[i];
	for(int i = 1; i <= n; i++){
		int test[110] = {0};
		for(int j = i + 1; j <= n; j++){
			vector<int> lie, test(n+1, 1);
			test[i] = test[j] = -1;
			int flag = 0;
			for(int z = 1; z <= n; z++){
				if(check[z] * test[abs(check[z])] < 0){
					lie.push_back(z);
					if(z == i || z == j)flag++;
				}
			}
			if(flag == 1 && lie.size() == 2){
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool isPrime(int test){
	if(test == 0 && test == 1)return false;
	else {
		for(int i = 2; i <= sqrt(test); i++)
			if(test%i == 0)return false;
		return true;

	}
}
int main(){
	int n, m;
	string str;
	cin >> n >> m >> str;
	for(int i = 0; i < n-m+1; i++){
		int t = stoi(str.substr(i, m));
		if(isPrime(t) == true){
			cout << str.substr(i,m);
			return 0;
		}
	}
	cout << "404";
	return 0;
}

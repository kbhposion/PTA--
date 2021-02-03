#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, start[110], in[110], p = 1, flag = 1, k = 1;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> start[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    while(in[p] >= in[p-1])p++;
    int index = p;
    while(start[p] == in[p])p++;
    if(p == n){
        printf("Insertion Sort\n");
        sort(in, in + index + 1);
        for(int i = 0; i < n; i++)
            if(i == 0)printf("%d", in[i]);
            else printf(" %d", in[i]);
    }else{
        printf("Merge Sort\n");
        while(flag){
            flag = 0;
            for(int i = 0; i < n; i++)
                if(start[i] != in[i])flag = 1;
            k *= 2;
            for(int i = 0; i < n/k; i++)
                sort(start+i*k, start+(i+1)*k);
            sort(start+n/k*k, start+n);
        }
        for(int i = 0; i < n; i++)
            if(i == 0)printf("%d", start[i]);
            else printf(" %d", start[i]);
    }
    return 0;
}
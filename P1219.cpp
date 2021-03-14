#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
using namespace std;
typedef long long ll;
int a[100],b[100],c[100],d[100];// 行列八
int arr[3][15];
int n,num;
int dfs(int now){
    if (now==n){
        if(num<3){
            for (int i = 0; i < n; ++i) {
                cout<<a[i]+1<<' ';
            }
            cout<<endl;
            num++;
        }
        return 1;
    }
    int res=0;
    for(int j=0;j<n;j++){
        if(b[j]==0&&c[now+j]==0&&d[n-now+j]==0){
            a[now]=j;
            b[j]=1;
            c[now+j]=1;
            d[n-now+j]=1;
            res+=dfs(now+1);
            b[j]=0;
            c[now+j]=0;
            d[n-now+j]=0;
        }
    }
    return res;
}
int main(){
    cin>>n;
    cout<<dfs(0);;
}


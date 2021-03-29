#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
vector<vector<int> >res(105,vector<int>(105,-1));
vector<vector<int> > v(105,vector<int>(105,-1));
int setRes(int i,int j){
    int Max=1;
    if (res[i][j]!=-1)
        return res[i][j];
    if(i-1>=0&&v[i-1][j]<v[i][j]){
        Max=max(Max,1+setRes(i-1,j));
    }
    if (i+1<n&&v[i+1][j]<v[i][j]){
        Max=max(Max,1+setRes(i+1,j));
    }
    if (j-1>=0&&v[i][j-1]<v[i][j]){
        Max=max(Max,1+setRes(i,j-1));
    }
    if (j+1<m&&v[i][j+1]<v[i][j]){
        Max=max(Max,1+setRes(i,j+1));
    }
    res[i][j]=Max;
    return Max;
}

int main(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>v[i][j];
        }
    }
    int r=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            r=max(r,setRes(i,j));
        }
    }
    cout<<r<<endl;
    return 0;
}

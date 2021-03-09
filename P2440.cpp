//
// Created by Administrator on 2021/3/9.
//
#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;

vector<int>v;
int n,k;
bool isOk(int x){
    ll kk=0;
    for(int i=0;i<v.size();i++){
        kk+=v[i]/x;
    }
    if(kk>=k)
        return true;
    return false;
}
int erfen(int l,int r){
    if(l==r||l+1==r)return l;
    int m=(l+r)/2;
    if(isOk(m)){
        return erfen(m,r);
    }else{
        return erfen(l,m);
    }
}
int main(){
    cin>>n>>k;
    int l=0,r=100000000;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d",&t);
        r=min(r,t);
        v.push_back(t);
    }
    cout<<erfen(l,r+1)<<endl;
}

#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int>&p1,pair<int,int>&p2){return p1.second<p2.second;}
int main(){
    int l,n,m,left,right,mid,now,i,a[50005],s,ans;
    cin>>l>>n>>m;
    for(i=1;i<=n;i++)
        cin>>a[i];   //输入
    left=0;right=l;
    while(left<=right){
        mid=(right+left)/2;
        now=0;s=0;
        for(i=1;i<=n;i++){
            if(a[i]-a[now]<mid)
                s++;
            else now=i;}
        if(s<=m){
            ans=mid;
            left=mid+1;}
        else right=mid-1;}
    cout<<ans;
    return 0;}
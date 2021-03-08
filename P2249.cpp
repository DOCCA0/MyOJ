#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
using namespace std;
const int maxn=1e5+5;
int main()
{
     int n,m,res;
     scanf("%d %d",&n,&m);
     map<int,int> map;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d",&t);
        if (!map.count(t)){
            map.insert({t,i});
        }
    }
    for (int i = 0; i < m; ++i) {
        int t;
        cin>>t;
        if (map.count(t)){
            cout<<map[t]<<' ';
        }else{
            cout<<-1<<' ';
        }
    }
}

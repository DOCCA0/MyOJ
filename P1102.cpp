#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
using namespace std;
typedef long long ll;
int main(){
    ll n,c;
    scanf("%lld %lld",&n,&c);
    map<ll,ll> map1;//各个数出现的次数
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%lld",&t);
        if (!map1.count(t)){
            map1.insert({t,1});
        }else{
            map1[t]++;
        }
    }
    ll res=0;
    for (auto it=map1.begin();it!=map1.end();it++) {
        pair<ll,ll>p=*it;
        if(map1.count(p.first+c))
            res+=p.second*map1[p.first+c];
    }
    cout<<res<<endl;
}
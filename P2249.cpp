#include<iostream>
#include<algorithm>
using namespace std;
int maxn=1e6+5;
int main(int argc, char const *argv[])
{
     int n,m,res;
     cin>>n>>m;
     int arr[maxn];
     // fill_n(arr,maxn,0);
     for(int i=0;i<n;i++){
         cin>>arr[i];
     }
     for (int i = 0; i < m; i++)
     {
         int t;
         res=lower_bound(arr,arr+n,t)-arr;
     }
     if(res!=n)
         cout<<res<<' ';
     else
         cout<<-1<<' ';
     return 0;
}

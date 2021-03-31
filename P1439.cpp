#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
int str1[100005];
int str2[100005];
int n;
int arr[100][100];
int getRes(int n1,int n2){
    if (n1==-1||n2==-1)
        return 0;
    if(str1[n1]==str2[n2]){
        return getRes(n1-1,n2-1)+1;
    }else{
        return max(getRes(n1-1,n2),getRes(n1,n2-1));
    }
}
int main(){
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>str1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>str2[i];
    }
    cout<<getRes(n-1,n-1)<<endl;
}
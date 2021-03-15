#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <map>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;
int dx[8]={-1,+1,-1,+1,-2,+2,-2,+2};
int dy[8]={-2,-2,+2,+2,-1,-1,+1,+1};
int n,m;
int arr[405][405];
int vis[405][405];
bool isOk(int row,int line){
    if(row<0||row>=n||line<0||line>=m)
        return false;
    if (vis[row][line]!=-1)
        return false;
    vis[row][line]=1;
    return true;
}
void bfs(int row,int line){
    queue< pair<pair<int,int>,int> > q;
    q.push({{row,line},0});
    vis[row][line]=1;
    while (!q.empty()){
        pair<pair<int,int>,int> now=q.front();
        q.pop();
        int r=now.first.first;
        int l=now.first.second;
        int len=now.second;
        arr[r][l]=len;
        for(int i=0;i<8;i++){
            if(isOk(r+dx[i],l+dy[i]))
                q.push({{r+dx[i],l+dy[i]},len+1});
        }
    }
}
int main(){
    int a,b;
    cin>>n>>m>>a>>b;
    memset(arr,-1,sizeof((arr)));
    memset(vis,-1,sizeof((vis)));
    bfs(a-1,b-1);
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; ++j) {
            printf("%-5d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

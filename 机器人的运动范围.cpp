#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
    set<pair<int,int> >visited;
    int m,n,k;
public:
    int movingCount(int m, int n, int k) {
        this->m=m;
        this->n=n;
        this->k=k;
        bfs();
        return visited.size();
    }
    void bfs(){
        queue<pair<int,int> > q;
        q.push(pair<int,int>(0,0));
        visited.insert({0,0});
        while (!q.empty()){
            pair<int,int> now=q.front();
            int nowi=now.first;
            int nowj=now.second;
            q.pop();
            if(canIn(nowi-1,nowj)&&!visited.count(pair<int,int>(nowi-1,nowj))){
                q.push(pair<int,int>(nowi-1,nowj));
                visited.insert(pair<int,int>(nowi-1,nowj));
            }
            if(canIn(nowi+1,nowj)&&!visited.count(pair<int,int>(nowi+1,nowj))){
                q.push(pair<int,int>(nowi+1,nowj));
                visited.insert(pair<int,int>(nowi+1,nowj));
            }
            if(canIn(nowi,nowj-1)&&!visited.count(pair<int,int>(nowi,nowj-1))){
                q.push(pair<int,int>(nowi,nowj-1));
                visited.insert(pair<int,int>(nowi,nowj-1));
            }
            if(canIn(nowi,nowj+1)&&!visited.count(pair<int,int>(nowi,nowj+1))){
                q.push(pair<int,int>(nowi,nowj+1));
                visited.insert(pair<int,int>(nowi,nowj+1));
            }
        }
    }
    bool canIn(int i,int j){
        if (i<0||j<0||i>=m||j>=n)
            return false;
        return numSum(i)+numSum(j)<=k;
    }
    int numSum(int num){
        int r=0;
        while (num!=0){
            r+=num%10;
            num/=10;
        }
        return r;
    }
};
int main(){
    Solution s;
    cout<<s.numSum(35);
}
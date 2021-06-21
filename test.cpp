#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    set<string>set;
    string s;
    string resstr;
    vector<string>res;
    vector<int> v{0,0,0,0,0,0,0,0,0};
public:
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        this->s=s;
        dfs(0);
        return res;
    }
    void dfs(int step){
        if(step==s.size()){
            if (!set.count(resstr)){
                res.push_back(resstr);
                set.insert(resstr;)
            }
            return;
        }
        for(int i=0;i<s.size();i++){
            if(v[i]==0){
                resstr.push_back(s[i]);
                v[i]=1;
                dfs(step+1);
                resstr.pop_back();
                v[i]=0;
            }
        }
    }
};
int main(){
    Solution s;
}
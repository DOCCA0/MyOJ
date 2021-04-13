//
// Created by wu on 2021/4/12.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numWays(int n) {
        cout<<n<<endl;
        if(n==0)return 1;
        if(n==1)return 1;
        int res=0;
        for(int i=1;i<n;i++){
            res=res+numWays(i)+numWays(n-i);
            res%=1000000007;
        }
        return res%1000000007;
    }
};
int main(){

    Solution s;
    s.numWays(2);
    return 0;
}
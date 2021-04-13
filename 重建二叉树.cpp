//
// Created by wu on 2021/4/12.
//

#include <vector>
#include <set>
#include <map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    vector<int> preorder;
    vector<int> inorder;
    map<int,int> prem;
    map<int,int> inm;
public:
    TreeNode* build(int i1,int j1,int i2,int j2){
        TreeNode treeNode(preorder[i1]);
        int index1=inm[preorder[i1]];
        int leftsize=index1-i2;
        if(i1==j1)
            treeNode.left=NULL;
        else
            treeNode.left=build(i1+1,i1+leftsize,i2,index1-1);
        if (i2==j2)
            treeNode.right=NULL;
        else
            treeNode.right=build(i1+leftsize+1,j1,index1+1,j2);
        return &treeNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); ++i) {
            this->preorder.push_back(preorder[i]);
            prem.insert({preorder[i],i});
        }
        for (int i = 0; i < inorder.size(); ++i) {
            this->inorder.push_back(inorder[i]);
            inm.insert({preorder[i],i});
        }
        return build(0,preorder.size()-1,0,inorder.size()-1);
    }
};
int main(){
    Solution s;
    vector<int >pre,in;
    pre.push_back(3);
    pre.push_back(9);
    pre.push_back(20);
    pre.push_back(15);
    pre.push_back(7);

    pre.push_back(9);
    pre.push_back(3);
    pre.push_back(15);
    pre.push_back(20);
    pre.push_back(7);

    s.buildTree(pre,in);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// merge two binary trees采用的是新建一颗二叉树的方法。直接修改两颗树的任意一颗都会导致紊乱。
// 很明显的重叠子问题，可以使用递归解决。
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2){
            return nullptr;
        }
        if(!t1 && t2){
            return t2;
        }
        if(t1 && !t2){
            return t1;
        }
        TreeNode* merged_root = new TreeNode(t1->val+t2->val);
        merged_root->left = mergeTrees(t1->left, t2->left);
        merged_root->right = mergeTrees(t1->right, t2->right);
        return merged_root;
    }
};

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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        // root->left = invertTree(root->right);  // 调用不和法，导致left和right的递归调用，死循环。
        // root->right = invertTree(root->left);
        TreeNode* l = invertTree(root->right);
        TreeNode* r = invertTree(root->left);
        root->left = l;
        root->right = r;
        return root;
    }
};
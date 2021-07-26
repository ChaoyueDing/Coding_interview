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

 
 // 求二叉树的最大深度，即最大路径上的节点个数。len_curr = max(len_l, len_r)+1;
 // 此外当前节点的最大直径为res = max(res, len_l+len_r)
 // 使用后续遍历post_traversal
 // 本质：使用深度优先搜索，即后序遍历，计算每个节点的左右子树的深度，得到当前节点的深度，并且根据res_curr = len_l+len_r计算最大直径。
 // res是二叉树的直径，最长路径中边的个数，depth_of_tree是二叉树的深度，即路径中节点的个数。
class Solution {
public:
    int res = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        depth(root);
        return res;
    }

    int depth(TreeNode* root){
        if(root == nullptr)
            return 0;
        int len_l = depth(root->left);
        int len_r = depth(root->right);
        if(len_l + len_r > res){
            res = len_l + len_r;
        }
        return max(len_l, len_r) + 1;
    }
};
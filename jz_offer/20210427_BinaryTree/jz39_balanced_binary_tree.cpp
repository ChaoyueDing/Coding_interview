/* basic knowledge
平衡二叉树（Balanced Binary Tree），具有以下性质：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，
并且左右两个子树都是一棵平衡二叉树。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* solution 在计算binary tree的深度的代码的基础上，模改dfs函数，
若当前子树不是平衡二叉树，则当前子树的深度为-1，
*/

int dfs(TreeNode* root){
    if(root == NULL)
        return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if(left==-1 || right == -1)
        return -1;
    return abs(left-right)>1 ? -1 : max(left, right)+1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
            return dfs(root)!=-1;        
    }
};
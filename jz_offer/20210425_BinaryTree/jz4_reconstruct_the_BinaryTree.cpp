/* basic knowledge
preorder traversal: root->left->right
inorder traversal: left->root->right
postorder traversal: left->right->root
breadth-first traversal: traverse by layer
*/

// method 1: recursion
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int, int> m1;

TreeNode* subReCons(vector<int> preorder,vector<int> inorder, 
                   int pre_l, int pre_r, int in_l, int in_r){  //***写成了int in_l.
    //***递归一定要写递归边界
    if(pre_l>pre_r || in_l>in_r)
        return NULL;  //***如果没有左子树或者右子树，则子树为空。
    int pre_root = pre_l;
    int in_root = m1[preorder[pre_root]];  //***map应该查找一个值，而不是一个索引
    TreeNode* root = new TreeNode(preorder[pre_root]);
    int l_sub_size = in_root - in_l;
    root->left = subReCons(preorder, inorder, pre_l+1, pre_l+1+l_sub_size-1, in_l, in_root-1);
    root->right = subReCons(preorder, inorder, pre_l+l_sub_size+1, pre_r, in_root+1, in_r);
    return root;
}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> preorder,vector<int> inorder) {
        int n = inorder.size();
        for(int i=0; i<preorder.size(); i++){
            m1[inorder[i]]=i;  // 存inorder每个元素的索引，为了快速定位root的索引
        }
        return subReCons(preorder, inorder, 0, n-1, 0, n-1);
    }
};


// method 2: iteration
// too complicated, write later

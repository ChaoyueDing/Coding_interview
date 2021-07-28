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
    map<int, int> hash;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        for(int i=0; i<len; i++){  // 构造哈希快速定位inorder中的根节点
            hash[inorder[i]] = i;
        }
        return build_sub_tree(preorder, inorder, 0, len-1, 0, len-1);
    }

    TreeNode* build_sub_tree(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right){
        //**忘记写递归边界，导致heap-buffer-overflow
        if(pre_left > pre_right || in_left>in_right)
            return nullptr;
        int root_val = preorder[0];
        TreeNode* curr_node = new TreeNode(preorder[pre_left]);
        int pos_in_root = hash[preorder[pre_left]];  //***!!!忽略了递归，写成了preorder[0],导致stack-overflow
        int len_left_tree = pos_in_root-in_left;
        // int pos_in_root = *find(inorder.begin(), inorder.end(), root_val);  //***是迭代器指向的元素，并不会产生下标
        // int pos_pre_left_end = *find(inorder.begin(), inorder.end(), inorder[pos_in_root-1]);
        curr_node->left = build_sub_tree(preorder, inorder, pre_left+1, pre_left+len_left_tree, in_left, pos_in_root-1);
        curr_node->right = build_sub_tree(preorder, inorder, pre_left+len_left_tree+1, pre_right, pos_in_root+1, in_right);
        return curr_node;
    }
};
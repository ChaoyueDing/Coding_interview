#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 创建一个新函数inorderTra进行中序遍历，不使用原函数是应为原函数的参数列表不太好，返回是vector处理也不方便。类似于dfs，bfs。
// 使用insert或者merge进行vector拼接。
// 经验：深搜广搜return vector还不如return空+传参&vector来的方便。
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTra(root, res);
        return res;
    }

    void inorderTra(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        inorderTra(root->left, res);
        res.push_back(root->val);
        inorderTra(root->right, res);
        return;
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        queue<TreeNode*> layer_traversal;
        vector<vector<int>> res;
        vector<int> tmp;
        layer_traversal.push(root);
        while(!layer_traversal.empty()){
            tmp = {};
            int layer_len = layer_traversal.size();
            for(int i=0; i<layer_len; i++){
                TreeNode *curr_node = layer_traversal.front(); 
                tmp.push_back(curr_node->val);
                if(curr_node->left != nullptr)
                    layer_traversal.push(curr_node->left);
                if(curr_node->right != nullptr)  //***写成了left
                    layer_traversal.push(curr_node->right);
                layer_traversal.pop();
            }
            res.push_back(tmp);
        }
        return res;
    }
};
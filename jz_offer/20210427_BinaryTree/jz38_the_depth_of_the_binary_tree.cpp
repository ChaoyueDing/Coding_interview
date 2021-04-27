/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/* solution 1
使用preorder traversal，二叉树的深度即为递归的最大深度。
dfs(): 返回当前root的深度，即返回当前root节点的左子树的深度和右子树的深度中较大的那个。
*/

int dfs(TreeNode* root, int depth){
    if(root==NULL){
        return depth-1;
    }
    return max(dfs(root->left, depth+1), dfs(root->right, depth+1));
}

class Solution {
public:
    int TreeDepth(TreeNode* root) {
        return dfs(root, 1);
    }
};

/* solution 2
一棵二叉树的最大深度等于左子树深度和右子树最大深度的最大值 + 1
maxDepth()返回当前子树的深度
*/

int maxDepth(TreeNode* root){
    if(root==NULL)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

class Solution {
public:
    int TreeDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
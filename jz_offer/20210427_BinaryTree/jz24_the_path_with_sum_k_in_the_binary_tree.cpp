/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

void dfs(TreeNode* root, int num, vector<vector<int>>& res, vector<int>& tmp, int sum){
//***dfs中的函数vector等容器一定要取引用，最终的值不会更着函数的值而变化
    if(root==NULL){
        return;
    }
    sum += root->val;
    tmp.push_back(root->val);
    if(sum==num && root->left==NULL && root->right==NULL)
        res.push_back(tmp);
    
    dfs(root->left, num, res, tmp, sum);
    dfs(root->right, num, res, tmp, sum);
    
    sum -= root->val;
    tmp.pop_back();
}

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int num) {
        vector<vector<int>> res;
        vector<int> tmp;
        int sum=0;
        dfs(root, num, res, tmp,sum);
        return res;
    }
};
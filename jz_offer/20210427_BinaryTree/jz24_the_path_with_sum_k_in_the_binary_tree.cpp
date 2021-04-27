/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/* solutions
pathSum(root, sum) 函数：

初始化： 结果列表 res ，路径列表 path 。
返回值： 返回 res 即可。
recur(root, tar) 函数：

递推参数： 当前节点 root ，当前目标值 tar 。
终止条件： 若节点 root 为空，则直接返回。
递推工作：
路径更新： 将当前节点值 root.val 加入路径 path ；
目标值更新： tar = tar - root.val（即目标值 tar 从 sum 减至 00 ）；
路径记录： 当 ① root 为叶节点 且 ② 路径和等于目标值 ，则将此路径 path 加入 res 。
先序遍历： 递归左 / 右子节点。
路径恢复： 向上回溯前，需要将当前节点从路径 path 中删除，即执行 path.pop() 。
*/

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
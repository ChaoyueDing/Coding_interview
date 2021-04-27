/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        if(pRoot==NULL)
            return NULL;
        TreeNode* root = new TreeNode(pRoot->val);
        root->left = Mirror(pRoot->right);
        root->right = Mirror(pRoot->left);
        return root;  //***不知道要写return root
    }
};
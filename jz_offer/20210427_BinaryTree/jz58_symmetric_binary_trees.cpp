/* solutions
采用递归的方法解决该题。判断二叉树是否为镜像涉及到的是左右两个子树，和根结点没有关系。因此定义函数isSymmetricCore，将两个子树头结点A、B作为传入函数的参数。
设置退出情况：

如果A、B都为空，说明前面的判断都已经满足要求，因此返回值为true
如果A和B中有一个为空，显然不匹配
如果A和B都不为空，判断A和B的值是否相等，如果相等，则继续比较A的左子树和B的右子树以及A的右子树和B的左子树；如果不等，则返回false
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
public:
    bool isSym(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)  // 都为空
            return true;
        else if(left==NULL || right==NULL)  // 一个为空
            return false;
        else if(left->val == right->val){  // 都不为空
            return isSym(left->left, right->right) && isSym(left->right, right->left);
            // 左子树的右子树和右子树的左子树，左子树的左子树和右子树的右子树要对称。
        }
        else
            return false;
    }
    
    bool isSymmetrical(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSym(root->left, root->right);
    }
};
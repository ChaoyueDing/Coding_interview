/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/* solution: preorder traversal + recursive judgement
若树 B 是树 A 的子结构，则子结构的根节点可能为树 A 的任意一个节点。因此，判断树 B 是否是树 A 的子结构，需完成以下两步工作：
先序遍历树 A 中的每个节点An（对应函数 isSubStructure(A, B)）
判断树 A 中 以 An为根节点的子树 是否包含树 B 。（对应函数 recur(A, B)）
*/

bool recur(TreeNode* A, TreeNode* B){
    if(B==NULL)
        return true;
    if(A==NULL || A->val!=B->val)
        return false;
    return recur(A->left, B->left) && recur(A->right, B->right);
}

class Solution {
public:
    bool HasSubtree(TreeNode* A, TreeNode* B) {
        if(A==NULL || B==NULL)
            return false;
        return recur(A, B) || HasSubtree(A->left, B) || HasSubtree(A->right, B); 
    }
};
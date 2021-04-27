/* solution 1: 中序遍历，输出第k个值。
*/
class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &res){
        if(root==NULL)
            return;
        inorder(root->left, res);
        res.push_back(root);
        inorder(root->right, res);
    }
    
    TreeNode* KthNode(TreeNode* root, int k) {
        if(root==NULL)
            return NULL;
        vector<TreeNode*> res;
        inorder(root, res);
        if(k<=0 || k>res.size())  //***边界好好想一想，写成了(k<0 || k>=res.size())
        // 因为是第k小，所以k一定要大于0，k一定要小于元素个数res.size()
            return NULL;
        return res[k-1];
    }
};


/* solution 2: 剪枝，当访问第k小的元素时，直接return，每return一次减一，使得k==0的条件只能达成一次。
*/
class Solution {
public:
    TreeNode* res=NULL;  //***指针需要初始化为空。
    int k=-100;  //***定义变量好的习惯是初始化一下，初始化的值总比随机值要好
    void inorder(TreeNode* root){  //***指针也要加引用，只要是dfs需要最终传出的结果都要加。
        // 或者定义成公有变量
        if(root==NULL)
            return;
        // k--; 不能放在这里，不然if(k==0)处永远不会成立，更成立时，不能立即判断，就要被左子节点再减1
        inorder(root->left);
        if(--k==0){  //***--和k的判断一定要放在一起，不能放在inorder的前面后者后面，不然非常麻烦
            res = root;
            return;
        }
        // k--; 不能放在这里，一定要放在return之前，不然会出现递归return的情况，因为回溯时，k一直等于1
        inorder(root->right);
    }
    
    TreeNode* KthNode(TreeNode* root, int k) {
        if(root==NULL)
            return NULL;
        this->k = k;
        inorder(root);
        return res;
    }
};
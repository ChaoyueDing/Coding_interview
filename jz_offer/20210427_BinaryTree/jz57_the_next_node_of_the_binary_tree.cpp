/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

/* solution
先preorder traversal保存遍历序列，然后从遍历序列中找到当前元素的下一个元素。
1. 根据给出的结点求出整棵树的根节点
2. 根据根节点递归求出树的中序遍历，存入vector
3. 在vector中查找当前结点，则当前结点的下一结点即为所求。
*/
void inorder(TreeLinkNode* root, vector<TreeLinkNode*> &res){  //***常见错误，dfs的vector忘加引用而导致出现数组内存越界的错误
    if(root == NULL)
        return;
    inorder(root->left, res);
    res.push_back(root);
    inorder(root->right, res);
}

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if(pNode==NULL)
            return NULL;
        vector<TreeLinkNode*> res;
        TreeLinkNode* root = pNode;
        // step 1
        while(root->next!=NULL){
            root = root->next;
        }
        // step 2
        inorder(root, res);
        // step 3
        for(int i=0; i<res.size()-1; i++){
            if(res[i] == pNode)
                return res[i+1];
        }
        return NULL;
    }
};

/* solution 2
1. 有右子树，下一结点是右子树中的最左结点，例如 B，下一结点是 H
2. 无右子树，且结点是该结点父结点的左子树，则下一结点是该结点的父结点，例如 H，下一结点是 E
3. 无右子树，且结点是该结点父结点的右子树，则我们一直沿着父结点追朔，直到找到某个结点是其父结点的左子树，
如果存在这样的结点，那么这个结点的父结点就是我们要找的下一结点。例如 I，下一结点是 A；
例如 G，并没有符合情况的结点，所以 G 没有下一结点
*/

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 1.
        if(pNode->right != NULL){
            TreeLinkNode* pRight = pNode->right;
            while(pRight->left!=NULL){
                pRight = pRight->left;
            }
            return pRight;
        }
        // 2.
        if(pNode->next!=NULL && pNode->next->left==pNode)
            return pNode->next;
        if(pNode->next!=NULL && pNode->next->right==pNode){
            TreeLinkNode* pNext = pNode;
            while(pNext->next!=NULL){
                if(pNext->next->left==pNext)
                    //***写成了==pNext->next,父节点的left怎么可能等于父节点呢？
                    return pNext->next;
                pNext = pNext->next;
            }
        }
        return nullptr;
    }
};
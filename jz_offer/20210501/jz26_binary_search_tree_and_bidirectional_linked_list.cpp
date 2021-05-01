/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/* solution
指针pre指向前驱节点，指针curr指向当前节点。
pre初始化为空，curr初始化为head，并且在中序遍历dfs()中修改指针指向。
1. 递归左子树
2. 修改根节点引用
3. 递归右子树
*/

// 1. 双向循环链表
class Solution {
public:
    TreeNode* pre=NULL, *head;  // 技巧，如果有变量需要传给dfs，直接定义成类的私有或公有变量即可
    
    void dfs(TreeNode* curr){
        if(curr==NULL)
            return;
        dfs(curr->left);
        // 调整当前节点的left和right，使其成为链表，并记录pre
        if(pre == NULL){  // 特例，链表的头节点
            head = curr;
        }
        else{
            pre->right = curr;
            curr->left = pre;
        }
        pre = curr;
        dfs(curr->right);
    }
    
    TreeNode* Convert(TreeNode* root) {
        if(root==NULL)
            return NULL;
        dfs(root);
        // 调整链表头尾指向，使其成为循环链表
        pre->right = head;
        head->left = pre;
        return head;
    }
};



// 1. 双向链表
class Solution {
public:
    TreeNode* pre=NULL, *head;  // 技巧，如果有变量需要传给dfs，直接定义成类的私有或公有变量即可
    
    void dfs(TreeNode* curr){
        if(curr==NULL)
            return;
        dfs(curr->left);
        // 调整当前节点的left和right，使其成为链表，并记录pre
        if(pre == NULL){  // 特例，链表的头节点
            head = curr;
        }
        else{
            pre->right = curr;
            curr->left = pre;
        }
        pre = curr;
        dfs(curr->right);
    }
    
    TreeNode* Convert(TreeNode* root) {
        if(root==NULL)
            return NULL;
        dfs(root);
        //***请看清楚题目是双向链表还是双向循环链表。
//         // 调整链表头尾指向，使其成为循环链表
//         pre->right = head;
//         head->left = pre;
        return head;
    }
};
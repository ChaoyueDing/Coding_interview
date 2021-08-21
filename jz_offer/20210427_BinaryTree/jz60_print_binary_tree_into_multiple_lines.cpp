#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


/* solution
特例处理： 当根节点为空，则返回空列表 [] ；
初始化： 打印结果列表 res = [] ，包含根节点的队列 queue = [root] ；
BFS 循环： 当队列 queue 为空时跳出；
    新建一个临时列表 tmp ，用于存储当前层打印结果；
    当前层打印循环： 循环次数为当前层节点数（即队列 queue 长度）；
        出队： 队首元素出队，记为 node；
        打印： 将 node.val 添加至 tmp 尾部；
        添加子节点： 若 node 的左（右）子节点不为空，则将左（右）子节点加入队列 queue ；
    将当前层结果 tmp 添加入 res 。
返回值： 返回打印结果列表 res 即可。
*/


class Solution {
public:
        vector<vector<int> > Print(TreeNode* root) {
            // res存储最终结果
            // temp存储每一层的结果
            // que为队列，保存每一层的节点指针
            vector<vector<int>> res;
            vector<int> tmp;
            queue<TreeNode*> que;
            if(root==NULL)  //***忘记考虑特殊情况
                return res;  
            que.push(root);
            TreeNode* p;
            while(!que.empty()){
                int len = que.size();  //***对于每一层的打印循环次数（元素个数），应该使用静态值len，而不是动态值
                                   // que.size()，因为一旦que.push(x)之后，que的大小就会发生变化。
                for(int i=0; i<len; i++){  // 巧妙设计，因为que一直存储的为一行的元素，所以que.size即为当前行元素个数
                    p = que.front();
                    if(p->left!=NULL)
                        que.push(p->left);
                    if(p->right!=NULL)
                        que.push(p->right);                    
                    tmp.push_back(p->val);
                    que.pop();
                }
                res.push_back(tmp);
                tmp.clear();  //***对于每一层tmp加入到res，忘记清楚tmp.clear()。
            }
            return res;
        }
};
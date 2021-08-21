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

// solution 1: using queue

class Solution {
public:
    vector<vector<int> > Print(TreeNode* root){
            // res存储最终结果
            // temp存储每一层的结果
            // deque为双端队列，保存每一层的节点指针
            vector<vector<int>> res;
            vector<int> tmp;
            deque<TreeNode*> q;
            if(root==NULL)  //***忘记考虑特殊情况
                return res;  
            q.push_back(root);
            TreeNode* p;
            while(!q.empty()){
                int len = q.size();  //***对于每一层的打印循环次数（元素个数），应该使用静态值len，而不是动态值
                                   // q.size()，因为一旦q.push(x)之后，q的大小就会发生变化。
                if(res.size()%2 == 0){ // 当前为奇数行，前取后放：从左向右打印，所以从前边取，后边放入
                    for(int i=0; i<len; i++){  // 巧妙设计，因为q一直存储的为一行的元素，所以q.size即为当前行元素个数
                        p = q.front();
                        if(p->left!=NULL)
                            q.push_back(p->left);
                        if(p->right!=NULL)
                            q.push_back(p->right);                    
                        tmp.push_back(p->val);
                        q.pop_front();
                    }
                }
                else{  // 当前为偶数行，后取前放： 从右向左，从后边取，前边放入
                       // 因为从前端插入下一层的所有元素，并且是从右侧节点开始的，所以需要先右后左，这样才能保证下一层元素的顺序性
                    for(int i=0; i<len; i++){  // 巧妙设计，因为q一直存储的为一行的元素，所以q.size即为当前行元素个数
                        p = q.back();  //***此处写成了q.front()
                        //***后面四行忘记更换left和right的位置了
                        if(p->right!=NULL)
                            q.push_front(p->right);
                        if(p->left!=NULL)
                            q.push_front(p->left);               
                        tmp.push_back(p->val);
                        q.pop_back();
                    }
                }
                res.push_back(tmp);
                tmp.clear();  //***对于每一层tmp加入到res，忘记清楚tmp.clear()。
            }
            return res;
        }
};
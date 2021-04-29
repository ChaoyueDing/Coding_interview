# include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};


char* Serialize(TreeNode *root) {
    if(root == NULL)
        return "# ";
    ostringstream out;
    queue<TreeNode*> q;
    q.push(root);
//         out<<q.front()->val<<" ";
    while(!q.empty()){
        TreeNode* p = q.front();
        if(p==NULL){  //***空节点不存在左右子节点
            out<<"# ";
        }
        else{
            out<<p->val<<" ";
            q.push(p->left);
            q.push(p->right);
        }
        q.pop();
    }

    char* new_out = new char[out.str().size()];
    strcpy(new_out, (char*)out.str().data());
    return new_out;
}

// 将string存入vector
TreeNode* Deserialize(char *str) {
    vector<TreeNode*> vec;
    string str1 = str;
    string tmp;
    istringstream s(str1);
    while(s>>tmp){
        if(tmp=="#"){
            vec.push_back(NULL);
        }
        else{
            TreeNode* node = new TreeNode(stoi(tmp));
            vec.push_back(node);
        }
    }

    int j=1;
    int len = vec.size();
    for(int i=0; i<len; i++){
        if(vec[i]==NULL){
            continue;
        }
        else{
            if(j<len)
                vec[i]->left = vec[j++];
            if(j<len)
                vec[i]->right = vec[j++];               
        }
    }
    return vec[0];
}



int main(){
    TreeNode *root = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(8);
    root->left = node6;
    root->right = node7;
    node6->right = node8;
    char *sss = Serialize(root);
    Deserialize(sss);
    return 0;
}
/* solutions
recur函数用于判断区间[left, right]中的序列是否为一颗二叉查找树的postorder，
然后对于一个序列，right指向的元素一定是当前子树的root节点，然后从前往后扫描按照左子树一定小于root节点，
右子树一定大于root节点的特性，找到左子树和右子树的区间，然后使用递归进行判断，
注意，使用递归的递归边界为if(left >= right) return true;
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool recur(vector<int> seq, int left, int right){
        if(left >= right)  //***忘记写递归边界了，下次上来先写递归边界
                           //***递归边界写反了，写成了if(left<=right)
            return true;
        int root = right;
        int p = left;
        while(seq[p] < seq[root])
            p++;
        int left_end = p-1;
        while(seq[p] > seq[root])
            p++;
        int right_end = p-1;
        return right_end+1 == right && recur(seq, left, left_end) && recur(seq, left_end+1, right_end);            
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if(len==0)
            return false;
        return recur(sequence, 0, len-1);
    }
};
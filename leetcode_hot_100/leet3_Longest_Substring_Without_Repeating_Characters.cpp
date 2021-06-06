#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* solution: sliding window
    思路：涉及到次数->hash map哈希表；涉及到子串->滑动窗口
    什么时候结束扫描？  while(r>=len || l==r)
    如果右窗滑到边界怎么办？  当r++>=len的时候，跳出循环。
    如果左窗滑到边界怎么办？  不可能，因为左窗口永远不会超过右窗口
    左窗会超过右窗吗？  不会
    满足什么条件才记录当前窗口的长度？  如果num[l++]与不存在于窗口中，则win++，当不满足条件按时如果win>res，则res=win
    如何判断出现重复？  hash map
    */
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int l = 0;
        int r = 0;  //***左闭右开，窗口开始为空，所以r应该为0而不是1
        int res = 0;
        int win_len = 0;
        vector<int> s_hash(128, 0);
        while(r<len){  //***&&写成了||，r<len是为了防止r越界，l<=r是为了防止l越界，因为r会执行1-n步骤，l只会执行1步，所以l不可能超过r。
            while(r<len && s_hash[s[r]]==0){
                s_hash[s[r]]++;  //***s_hash[]里面写成了索引r，应该写成字符s[r]
                win_len++;
                r++;
            }
            if(win_len>res)
                res = win_len;
            s_hash[s[l]]--;
            win_len--;
            l++;
        }
        return res;
    }
};
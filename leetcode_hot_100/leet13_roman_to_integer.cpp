// 罗马数字：左侧数字比右侧数字小，则直接转换，如果左侧数字比右侧数字大，则需要将此数转化为负数，从前往后扫描即可。
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m1= {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return m1[s[0]];

        int res=0;
        for(int i=0; i<s.size()-1; i++){
            if(m1[s[i]]>=m1[s[i+1]]){  // 写成了>应该是>=
                res += m1[s[i]];
            }
            else{
                res += -m1[s[i]];
            }
        }
        res += m1[s[s.size()-1]];
        return res;
        
    }
};
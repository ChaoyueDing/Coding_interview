#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* 特殊情况
    1534236469 -> 966324351 个位数特别大，超过了2
    */
    stringstream ss;
    string str;
    int reverse(int x) {
        // if(x==INT_MIN+1)  //***错误，这道题不是正负转换，而是同符号数的逆序，不存在你说的这两种情况，你这是顺序+取负数
        //     return INT_MAX;
        // if(x==INT_MAX)
        //     return INT_MIN+1;        
        int x1;
        ss << x;
        ss >> str;
        std::reverse(str.begin(), str.end());
        ss.clear();
        ss << str;
        ss >> x1;
        if(x1==INT_MAX || x1==INT_MIN)  //***如果str超过了32位有符号整数范围，则stringstream转换后的整数为INT_MAX或者INT_MIN
            return 0;
        if(x<0)
            x1 *= -1;
        return x1;
    }
};
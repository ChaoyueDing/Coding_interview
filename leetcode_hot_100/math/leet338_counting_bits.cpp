#include<bits/stdc++.h>
using namespace std;

// x&(x-1) 去掉二进制数的最后一个1
// x&1 判断奇偶
// 动态规划递推公式，记忆化搜索：dp[n] = dp[n>>1] + n&1
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            dp[i] = dp[i>>1] + (i&1);  // 错误写法，因为按位与运算符&的优先级低于加减(正负号)，导致整体结果恒0
        }
        return dp;
    }
};
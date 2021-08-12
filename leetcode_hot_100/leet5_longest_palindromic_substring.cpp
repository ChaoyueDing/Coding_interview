#include<bits/stdc++.h>
using namespace std;

// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

/* 动态规划
状态转移方程: dp[i][j]表示子串[i, j]是不是回文串
dp[0][0] = 1
dp[i][j] = dp[i+1][j-1] s[i]==s[j]
dp[i][j] = 0
问题1：动态规划说从小到大，逐渐向[l,r]的两边扩散，但是问题是当l==0时，l-1不是会越界吗？它们代码里也不判断越界条件。
不是中心扩散，而是按列填写右上三角矩阵。
问题2：如何找到一个合适的循环，来枚举上述状态转移方法，从而实现递推的过程。
填写的是右上的三角矩阵，因为要满足i<=j的条件。
初始化矩阵的对角线为1。在循环当中，对角线相邻的元素ij必定相邻，即j-i=1，直接为true。对角线相邻相邻元素满足j-i==2，直接为true。
其他元素直接参考左下角(i+1, j-1)一定存在。注意只有两种可能的填充右上三角矩阵的方法，按行填和按列填写，按行填上面每行的元素
无法参考一下行左下角的内容。而按列填后一列的内容可以参考前一列的左下角内容，综上，按列填。
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int max_len = 1;
        int max_i = 0;
        vector<vector<int>> dp(len, vector<int>(len));
        for(int i=0; i<len; i++){
            dp[i][i] = 1;
        }
        for(int j=1; j<len; j++){
            for(int i=0; i<j; i++){
                if(s[i] != s[j]){
                    dp[i][j] = 0;
                }
                else{
                    if(j-i <= 2){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];  //***忘记状态转移了
                    }
                    if(dp[i][j]==1 && (j-i+1)>max_len){  //***放错位置了，直接放到上一个循环的else里面了
                                                         //***判断或循环中出现了“=”而不是“==”
                        max_len = j-i+1;
                        max_i = i;
                    }
                }
            }
        }
        return s.substr(max_i, max_len);
    }
};
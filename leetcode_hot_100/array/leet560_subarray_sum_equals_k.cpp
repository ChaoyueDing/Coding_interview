#include<bits/stdc++.h>
using namespace std;
// 和为k的子数组个数
// 使用前缀和prefix，pre为map<int, int>, pre[100]=2，代表前缀和为100的子数组有2个。
// pre[i] = pre[i-1] + nums[i]
// 对于每一个前缀和pre[i]，去前缀和map中寻找是否存在(pre[i]-k),加入pre[j]符合条件，则满足pre[i]-pre[j]=k,即nums[j+1]...nums[i]的和为k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> pre;
        int res = 0;
        int prefix = 0;
        pre[0] = 1;  // 重要初始化，前缀和为0有一种选择方法，即什么都不选。不设置为1会导致，前缀和pre[i]恰好为k时，会返回0，认为不符合条件。
        for(int i=0; i<len; i++){
            prefix = prefix + nums[i];
            if(pre.find(prefix-k)!=pre.end()){  // pre[i]-pre[j]=k -->> pre[i]-k=pre[j] -->> pre.find(pre[i]-k)
                res += pre[prefix-k];
            }
            pre[prefix]++;
        }
        return res;
    }
};
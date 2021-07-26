// 哈希表
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size() == 1){
            return {};
        }
        map<int, int> m1;
        vector<int> res;
        for(const auto i: nums){
            m1[i] ++;
        }
        for(int i=1; i<=nums.size(); i++){
            if(m1[i]==0)
                res.push_back(i);
        }
        return res;
    }
};

// 数组原地修改法，数组中一个元素出现一次，其他元素出现两次的那道，可以使用类似的方法，对于出现元素的位置乘以-1即可。
// 此题因为出现次数可能>2，所以此题采用+n或+(n+1)的方法。
// 原地修改(x对应于x-1索引处，采用+(len+1)的操作，+len会导致索引为-1)+取模还原，空间复杂度O(1)
// 如果操作为+n，则还原索引必须这样写：index = (i-1)%n这样不会出现-1，而不能这样写：index = (i%n)-1，这样会得到-1，如果要这样写，则需要对于每个
// 数+(n+1)即可。在i>n时，两式等价(i-1)%n == (i%n)-1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(const auto &num: nums){
            int index = (num-1)%len;
            nums[index] += len;  // 因为+len大于所有元素值。
        }

        for(int i=0; i<len; i++){
            if(nums[i] <= len){
                res.push_back(i+1);  // 将i位置对应的值加入res中。
            }
        }
        return res;
    }
};

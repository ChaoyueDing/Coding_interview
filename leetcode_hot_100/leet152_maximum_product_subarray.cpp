#include<bits/stdc++.h>
using namespace std;

// 空间复杂度O(n)解法
class Solution {
public:
    int max_subarray(vector<int> nums){
        int len = nums.size();
        int res = nums[0];
        vector<int> max_array(len);
        vector<int> min_array(len);
        max_array[0] = min_array[0] = nums[0];
        for(int i=1; i<len; i++){
            max_array[i] = max(max(nums[i]*max_array[i-1], nums[i]*min_array[i-1]), nums[i]);
            min_array[i] = min(min(nums[i]*max_array[i-1], nums[i]*min_array[i-1]), nums[i]);
        }
        for(int i=1; i<len; i++){
            if(max_array[i]>res){
                res = max_array[i];
            }
        }
        return res;
        // return *max_element(max_array.begin(), max_array.end());
    }
};

// 优化解法，空间复杂度O(1)解法
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        int max_value;
        int min_value;
        max_value = min_value = nums[0];
        for(int i=1; i<len; i++){
            int tmp = max(max(nums[i]*max_value, nums[i]*min_value), nums[i]);  //***如果tmp写成max_value，会导致min_value使用的max_value是i处的值，而不是i-1处的值。
            min_value = min(min(nums[i]*max_value, nums[i]*min_value), nums[i]);
            max_value = tmp;
            cout<<max_value<<" "<<min_value<<endl;
            if(max_value > res){
                res = max_value;
            }
        }
        return res;
    }
};
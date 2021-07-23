#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Bucket{
        int max_val = INT_MIN;
        int min_val = INT_MAX;
    };
    int maximumGap(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        if(len<2)
            return 0;
        int min_val = *min_element(nums.begin(), nums.end());
        int max_val = *max_element(nums.begin(), nums.end());
        int bucket_size = max(1, (max_val-min_val)/(len-1));  // bucket_size为平均间距，总长度/元素之间间距的个数
        int bucket_count = (max_val-min_val)/bucket_size+1;  //***为什么是+1，+1是为了让最后一个元素有地方放。因为桶是前闭后开的区间，pos=(v_max-min_val)/bucket_size，此时的pos应该放在最后一个桶中，例如[1, 1000],bucket_size=999,bucket_count=2，(1000-1)/999=1,buckets[1]为第二个bucket。
        vector<Bucket> buckets(bucket_count);  // 这里应该是桶的个数，写成了buckets(bucket_size)
        for(auto &v: nums){
            int pos = (v-min_val)/bucket_size;
            buckets[pos].max_val = max(v, buckets[pos].max_val);
            buckets[pos].min_val = min(v, buckets[pos].min_val);
        }
        
        int prev = -1;
        for(int i=0; i<bucket_count; i++){
            if(buckets[i].max_val==INT_MIN){  // 空桶跳过
                continue;
            }
            if(prev != -1)  // 避免前一个桶为空， 或者当前桶是第一个非空桶。
                res = max(res, buckets[i].min_val-buckets[prev].max_val);
            prev = i;
        }
        return res;
    }
};
#include<bits/stdc++.h>
using namespace std;

// solution 1 (violent solution): sort + 剪枝了的三重for循环
// 三重for循环,对于每一重for循环对应于first,second,third这三个数的索引.
// 每一重循环: 跳过重复元素,即 if(seconde==first+1 || nums[first]!=nums[first-1]) continue;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int first, second, third;
        int len = nums.size();
        vector<vector<int>> res;
        if(len<3)
            return {};
        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            return a<b;
        });
        for(first=0; first<len; first++){
            if(first==0 || nums[first]!=nums[first-1]){  // 写成!=0 + continue会导致失去短路的效果,使得addition of unsigned offset overflowed
                for(second=first+1; second<len; second++){
                    if(second==first+1 || nums[second]!=nums[second-1]){
                        for(third=second+1; third<len; third++){
                            if(third==second+1 || nums[third]!=nums[third-1]){
                                if(nums[first] + nums[second] + nums[third] == 0)
                                    res.push_back({nums[first], nums[second], nums[third]});
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};



// solution 2: sort + 两重for循环 + [second+third]双指针。
// 每一重循环: 跳过重复元素,即 if(seconde==first+1 || nums[first]!=nums[first-1]) continue;
// 第二重循环中的双指针，两个关键点，(1) third指针位于first循环中，故在second循环中是递减的。
// (2) 对于每一个second，我们要找到恰好nums[second]+nums[third]<=target(-nums[first])的third，故如果“>"则third++。
// (3) third不会小于等于second，否则会产生重复结果，故如果third==second,则break。
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int first, second, third;
        int len = nums.size();
        vector<vector<int>> res;
        if(len<3)
            return {};
        sort(nums.begin(), nums.end(), [](auto &a, auto &b){
            return a<b;
        });
        for(first=0; first<len; first++){
            if(first==0 || nums[first]!=nums[first-1]){  // 写成!=0 + continue会导致失去短路的效果,使得addition of unsigned offset overflowed
                third = len-1;
                for(second=first+1; second<len; second++){
                    if(second==first+1 || nums[second]!=nums[second-1]){
                        // for(third=second+1; third<len; third++){
                        //     if(third==second+1 || nums[third]!=nums[third-1]){
                        //         if(nums[first] + nums[second] + nums[third] == 0)
                        //             res.push_back({nums[first], nums[second], nums[third]});
                        // 对于每个second,找到临界点的third,并且在同一个first下,third是不可逆的递减的.因为second增大,third必然减小.
                        while(third>second && nums[second]+nums[third]>-nums[first]){
                            third--;
                        }
                        // 如果second和third重合,则break.
                        if(second >=third)
                            break;
                        if(nums[second] + nums[third] == -nums[first]){
                            res.push_back({nums[first], nums[second], nums[third]});
                        }
                    }
                }
            }
        }
        return res;
    }
};
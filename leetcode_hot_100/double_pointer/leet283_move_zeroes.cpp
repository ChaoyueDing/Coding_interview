#include<bits/stdc++.h>
using namespace std;

// i指向0，j遇到0不处理，遇到非0则与i交换，i++，j++。
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while(j<nums.size()){
            if(i==j && nums[j]!=0){
                i++;
                j++;
                continue;
            }   
            if(nums[j]!=0){  // 不能加i!=j剪枝，否则会导致j走i步骤，而产生调换整数序列顺序的问题，遇到整数应该并且i==j时候应该原地交换，或者特判。
                swap(nums[i++], nums[j++]);
                continue;
            }
            j++;
        }
    }
};
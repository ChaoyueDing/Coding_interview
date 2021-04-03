// jz6: 旋转数组的最小数字
// 暴力解法：使用*min_element(rArray.begin(), rArray.end());




// 二分查找1：每次二分找到有序区间，并记录最小值
/* 
简单思路：
while(left<righ)  // 循环结束还剩一个元素，此时，left==right
{
    if(nums[left]==nums[mid])
    {
        min_n = min(min_n, nums[left]);  //***此处忘记存储最小值，而且应该在left++前存储最小值
        left++;
        continue;
    }
    if(nums[left]<nums[mid])  // 左侧有序，去右侧找最小值
    {
        left=mid+1;
        min_n = min(min_n, nums[left]);
    }
    else  // 右侧有序，去左侧找最小值
    {
        min_n = min(min_n, nums[mid]);
    }
}
min_n = min(nums[left], min_n);
return min_n;
*/


int minNumberInRotateArray(vector<int> nums) {
        int len = nums.size();
        if(len==0)
            return 0;
        int left=0, right=len-1;
        int min_n=INT_MAX;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(nums[left]==nums[mid])  //***while循环中可以使用if+continue替换
            {
                min_n = min(min_n, nums[left]);
                left++;
                continue;
            }
            if(nums[left] < nums[mid])  // 左侧有序
            {
                min_n = min(min_n, nums[left]);
                left = mid+1;
            }
            else  // 右侧有序
            {
                min_n = min(min_n, nums[mid]);
                right = mid-1;
            }
        }
        min_n = min(nums[left], min_n);
        return min_n;
}




// 二分查找2：nums[mid]与nums[right]的值进行比较，每次搜索排除一半的区间，最终最小值处于left处
int minNumberInRotateArray(vector<int> nums) {
        int len = nums.size();
        if(len==0)
            return 0;
        int left=0, right=len-1;
        int min_n=INT_MAX;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid] < nums[right])  // 此时可以忽略右半区间
            {
                right = mid; //***为什么要right=mid而不是right=mid-1？因为{5，2，3}的结果是5。
                                 // 因为此时nums[mid]更小，并且可能是本题的最小值right = mid - 1把mid这个可能的最小值给跳过了。
            }
            if(nums[mid] > nums[right])  // 此时可以忽略右半区间
            {
                left = mid+1;
            }
            else  // 右侧有序
            {
                right--;
            }
        }
        return left;
}
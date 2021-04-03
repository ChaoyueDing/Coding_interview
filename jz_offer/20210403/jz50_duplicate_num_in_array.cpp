// jz50: 数组中重复的数字
// 时间复杂度：O(nlogn)
// 空间复杂度：logn快排递归栈空间

// sort+遍历数组
int duplicate(vector<int>& nums) {
    int len = nums.size();  //***len=nums.size()，代表数组中元素的个数，不需要-1
    if(len==1 || len==0)
        return -1;
    sort(nums.begin(), nums.end());
    cout<<nums[3]<<" n4 "<<nums[4]<<endl;;
    for(int i=0; i<len-1; i++)
    {
        int j=i+1;
        if(nums[i]==nums[j]){
            return nums[i];
        }
    }
    return -1;
}



// 使用set函数
int duplicate(vector<int>& nums) {
    set<int> s;
    for(const int &p:nums){
        if(s.count(p)==0)
            s.insert(p);
        else
            return p;
    }
    return -1;
}
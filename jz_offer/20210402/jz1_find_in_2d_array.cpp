// jz1: 二维数组中的查找
// 时间复杂度：O(M*N)，二维数组中的每个元素都被遍历，因此时间复杂度为二维数组的大小。
// 空间复杂度：O(1)

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
// 使用count()暴力扫描
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    // int xLen=array.size();
    // int yLen=array[0].size();
    // if(xLen==0 || yLen==0)  //***xLen==0写成了xLen==0导致if每次判断都为真，所以出bug先检查等号
    //     return false;
    // 上述写法漏考虑了array[0]不存在情况，需要改成下面的写法
    int xLen=matrix.size();
    if(xLen==0)
        return false;
    int yLen=matrix[0].size();
    if(yLen==0)
        return false;
    for(int i=0; i<xLen; i++)
        if(count(matrix[i].begin(), matrix[i].end(), target)>=1)
            return true;
    return false;
}




// 线性查找，逐行对比最大值，如果小则扫描本行；如果大，则扫描下一行
bool Find(int target, vector<vector<int> > array) {
    // int xLen=array.size();
    // int yLen=array[0].size();
    // if(xLen==0 || yLen==0)  //***xLen==0写成了xLen==0导致if每次判断都为真，所以出bug先检查等号
    //     return false;
    // 上述写法漏考虑了array[0]不存在情况，需要改成下面的写法
    int xLen=array.size();
    if(xLen==0)
        return false;
    int yLen=matrix[0].size();
    if(yLen==0)
        return false;
    for(int i=0; i<xLen; i++)  //***for循环带两个if语句忘记加大括号
    {
        if(target > array[i][yLen-1])
        {
            continue;
        }
        if(count(array[i].begin(), array[i].end(), target)>=1)  //***存在应该写大于等于1，写成了==1
            return true;            
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << 1;
    return 0;
}

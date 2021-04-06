#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> vec; // 好的二维数组定义方法，使用vec.resize(n, temp)
    vector<vector<int>> ans;
    vector<int> temp(2);
    vec.resize(n, temp);
    for (int i = 0; i < n; i++)
    {
        // cin >> vec[i][0] >> vec[i][1];
        scanf("%d%d", &vec[i][0], &vec[i][1]);  // 有时不通过可以加个\n试试
    }
    int a = 0;
    return 0;
}

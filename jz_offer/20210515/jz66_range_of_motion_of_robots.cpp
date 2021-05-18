/* DFS (Non-backtracking)
dfs,bfs,backtracking不加引用会引发血案，造成非常非常严重的后果。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int int2sum(int n){
        int tmp = 0;
        while(n != 0){
            tmp += n%10;
            n /= 10;
        }
        return tmp;
    }
    
    int dfs(int threshold, int x, int y, int rows, int cols, vector<vector<int>> &visited){  // a = sum four directions
        //***dfs,bfs,backtracking不加引用会引发血案，造成非常非常严重的后果。
        if(x<0 || x>=rows || y<0 || y>=cols)  //***cols写成了rols
            return 0;
        if(visited[x][y]!=1 || int2sum(x)+int2sum(y)>threshold){
            return 0;
        }     
        
        visited[x][y] = -1;
        int res = 1;  // 当前单元格也算一个结果
        for(int j=0; j<4; j++){
            res += dfs(threshold, x+dir[j], y+dir[j+1], rows, cols, visited);
        }        
//         int res = dfs(threshold, x+1, y, rows, cols, visited) + 
//             dfs(threshold, x-1, y, rows, cols, visited) +
//             dfs(threshold, x, y+1, rows, cols, visited) +
//             dfs(threshold, x, y-1, rows, cols, visited);
        return res;
    }
    
    int movingCount(int threshold, int rows, int cols) {
        if(threshold < 0)  //***忘记特殊条件
            return 0;
        
        vector<vector<int>> visited(rows, vector<int>(cols, 1));
        return dfs(threshold, 0, 0, rows, cols, visited);
    }
};
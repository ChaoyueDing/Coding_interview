#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};  //***dirs写错了，每次只能走一步{-1, 1, 0, 1, -1}
    int len_x, len_y;
    // 深搜，不需要定义visited，直接访问过的修改其值为'2'即可。
    int numIslands(vector<vector<char>>& grid) {
        int nums=0;
        len_x = grid.size();
        len_y = grid[0].size();
        for(int i=0; i<len_x; i++){
            for(int j=0; j<len_y; j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    nums++;
                }
            }
        }
        return nums;
    }

    void dfs(vector<vector<char>> &grid, int x, int y){
        if(x<0 || x>=len_x || y<0 || y>=len_y){
            return;
        }
        if(grid[x][y] != '1'){
            return;
        }
        grid[x][y] = '2';
        for(int i=0; i<4; i++){
            int curr_x = x+dirs[i];
            int curr_y = y+dirs[i+1];  //***写成了curr_y = x+dirs[i+1]
            dfs(grid, curr_x, curr_y);
        }
        return;
    }
};
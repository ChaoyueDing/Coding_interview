/*
3
1 3 2 1 2 3
1 2 3 1 2 3
3 3 3 1 2 3
0
-1
5
*/

#include<bits/stdc++.h>
using namespace std;

int min_cost;  //!!!全局变量的初始值应该在main函数的T循环中复制，否则其初始值只赋值一次。
int oA, oB, oC, x, y, z;
int max_val;
int min_val;

bool check(int A, int B, int C){
    if(A==B || B==C || A==C)  // 三正整数不同
        return false;

    if(B==max_val || B==min_val)  // 第二大值在A或C中
        return true;

    return false;
}

void dfs(int A, int B, int C, int cost){
    if(A<=0 || B<=1 || C<=1)  //!!!忘记判断正整数
        return;
    if(check(A, B, C) && cost<min_cost){
        min_cost = cost;
        return;
    }
    if(cost>min_cost)
        return;
    if(A>min_val-3)
        dfs(A-1, B, C, cost+x);
    if(B>min_val-3)
        dfs(A, B-1, C, cost+y);
    if(C>min_val-3)
        dfs(A, B, C-1, cost+z);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        min_cost = INT_MAX;  //!!!有多组测试用例时，忘记刷新全局变量的初始值。
        cin>>oA>>oB>>oC>>x>>y>>z;
        max_val = max(max(oA, oB), oC);
        min_val = min(min(oA, oB), oC);
        dfs(oA, oB, oC, 0);
        if(min_cost==INT_MAX)
            cout<<-1;
        else
            cout<<min_cost;
    }
    return 0;
}
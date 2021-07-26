#include<bits/stdc++.h>
using namespace std;

// solution: bit operation
class Solution {
public:
    int hammingDistance(int x, int y){
        int res=0;
        int xor_val = x^y;
        while(xor_val){
            res += xor_val&1;
            xor_val>>=1; //***错误写法xor_val>>1;
        }
        return res;
    }
};

int main(){
    int x = 123;
    cout<<x<<endl;
    x>>=1;  // 等同于x = x>>1;
    cout<<x;
    return 0;
}
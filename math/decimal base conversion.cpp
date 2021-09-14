// 华为20210909一面

#include<bits/stdc++.h>
using namespace std;

double convert_n(double m, int n){
    vector<int> result;
    int res = 0.0;
    double temp = 0.0;
    
    if(n<=0){
        return 0;
    }

    while(m != 0){
        temp = m*n;
        res = floor(temp);
        m = temp - res;
        result.push_back(res);
    }

    cout<<"0.";
    for(auto i: result){
        cout<<i;
    }
}

int main(){
    convert_n(0.8, 2);
    return 0;
}
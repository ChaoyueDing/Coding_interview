#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    set<int> s={1,2,3};
    // 
    cout << "使用auto p:s访问";
    for(auto i:s){
        cout<<i;
    }
    return 0;
}

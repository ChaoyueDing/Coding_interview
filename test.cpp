#include<bits/stdc++.h>
using namespace std;

int main(){
    int i = 23456;
    string str;
    stringstream ss;
    ss << i;
    ss >> str;
    cout << str << endl;
    cout << str.size();

    return 0;
}
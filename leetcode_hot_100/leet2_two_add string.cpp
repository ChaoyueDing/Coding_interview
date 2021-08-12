#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1 = "12345";
    string s2 = "234567890";
    string s;
    int len1 = s1.size(), len2 = s2.size();
    int add_zero = abs(len1-len2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if(len1<len2){
        s1.append(add_zero, '0');
    }
    ;
    if(len1>len2){
        s2.append(add_zero, '0');  //***string.append(times, char)
        // ite = vector.insert(ite, 3, 1);          //在ite位置插入三个1， 观察输出，ite指向的元素是 1
    }
    int carry = 0;
    for(int i=0; i<s1.size(); i++){
        int curr_sum = s1[i]-'0' + s2[i]-'0' +carry;
        carry = curr_sum/10;
        s.push_back((curr_sum%10)+'0');
    }
    if(carry!=0){
        s.push_back(carry);
    }
    reverse(s.begin(), s.end());
    cout<<s<<endl;
    return 0;
}
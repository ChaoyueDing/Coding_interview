#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    // 用一个栈来实现，每个元素包含两个值，(当前元素，当前最小值)。
    /** initialize your data structure here. */
    int curr_min = INT_MAX;
    stack<pair<int, int>> stk;
    MinStack() {

    }
    
    void push(int val) {
        curr_min = min(curr_min, val);
        stk.push(make_pair(val, curr_min));
    }
    
    void pop() {
        stk.pop();
        if(!stk.empty()){
            curr_min = stk.top().second;
        }
        else
            curr_min = INT_MAX;
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
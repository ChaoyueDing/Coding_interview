/* solution1: insert_sort
*/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    vector<int> vec;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(vec.empty()==true)
            vec.push_back(num);
        else{
            vec.insert(lower_bound(vec.begin(), vec.end(), num), num);
        }
    }
    
    double findMedian() {
        int len = vec.size();
        return len&1?vec[len/2]:(vec[len/2]+vec[len/2-1])/2.0;
    }
};


/* solution2: normal sort (time out)
*/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    vector<int> vec;
    MedianFinder() {

    }
    
    void addNum(int num) {
        vec.push_back(num);
    }
    
    double findMedian() {
        int len = vec.size();
        sort(vec.begin(), vec.end());
        return len&1?vec[len/2]:(vec[len/2]+vec[len/2-1])/2.0;
    }
};

/* solution2: less<int> & greater<int> priority queue
大根堆存较小的一半数字（相等或较多的一半），小根堆存较大的一半数字，
所有数字先进大根堆low,再进小根堆low，这样保证了high的个数>=low，如果low.size()<high.size，low.push(high.top())
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;
    void Insert(int num) {
        // 先进小，再进大
        low.push(num);
        high.push(low.top());
        low.pop();
        if(low.size()<high.size()){
            low.push(high.top());
            high.pop();
        }
    }

    double GetMedian() { 
        if(low.size() == high.size())
            return (low.top()+high.top())/2.0;
        else
            return low.top();
    }
};
// 调整数组顺序使奇数位于偶数前面
// 方法1，插入排序的思想：使用vec.insert(iter, num) + vec.erase(iter)实现
vector<int> reOrderArray(vector<int>& array) {
    int len = array.size();
    vector<int> res(len);
    int pivot=0;
    int i=0;
    while(i<len){
        if(array[i]%2 == 0){
            i++;
        }
        else{
            array.insert(array.begin()+pivot, array[i]);
            array.erase(array.begin()+i+1);
            pivot++;
            i++;
        }
    }
    return array;
}


// 方法2：创建新数组，两次遍历原数组，第一次存储所有奇数，第二次存储所有偶数
vector<int> reOrderArray(vector<int>& array) {
    int len = array.size();
    vector<int> res;  //***res写成了res(len)
    for(int i=0; i<len; i++){
        if(array[i]%2==1)
            res.push_back(array[i]);
    }
    for(int i=0; i<len; i++){
        if(array[i]%2==0)
            res.push_back(array[i]);
    }
    return res;
}


// 方法3，使用push_back()：创建两个数组odd & even，遇到奇数push_back()到odd，遇到偶数push_back()到even
vector<int> reOrderArray(vector<int>& array) {
    int len = array.size();
    vector<int> res1, res2;  //***res写成了res(len)
    for(int i=0; i<len; i++){
        if(array[i]%2==1)
            res1.push_back(array[i]);
    }
    for(int i=0; i<len; i++){
        if(array[i]%2==0)
            res2.push_back(array[i]);
    }
    res1.insert(res1.end(), res2.begin(), res2.end());
    return res1;
}


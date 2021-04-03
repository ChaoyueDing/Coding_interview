// jz44: 翻转单词顺序列
// 时间复杂度：
// 空间复杂度：
// c++ code: 连空格一起翻转（不带空格一起翻转难度极大）
string ReverseSentence(string str) {
    string s1="";
    int len = str.size();
    if(len==0 || len==1)
        return str;
    int start = len-1;
    for(int i=len-2; i>=-1; i--)
    {
        if(str[i]==' ' || i==-1)  //***str[i]==' '，此处为字符，写成了str[i]==" "
        {
            s1+=str.substr(i+1, start-i);  //***start-i应该是大减小，写成了i-start
            s1+=" ";  //***最后会多输出一个空格
            start = i-1;
        }
    }
    s1.erase(len,1);
    return s1;
}

// python code: 保留所有空格一起翻转
// 使用str1.split(), list1.reverse(), "-".join(list1)这三个函数
// def ReverseSentence(self, s):
//     if len(s)==' ' or len(s)==' ':
//         return s
//     list1 = s.split(' ')
//     list1.reverse()
//     s2 = " ".join(list1)
//     return s2


// python code: 首尾空格全部删除
// # 使用str1.split(), list1.reverse(), "-".join(list1)这三个函数
// def ReverseSentence(self, s):
//     if len(s)==' ' or len(s)==' ':
//         return s
//     list1 = s.split() #正确写法，忽略空字符，连续多个空格能全部忽略
//     # list1 = s.split(' ')***错误写法，会把两个空格之间的空字符当成一个字符来看待
//     # "the sky is    blue"
//     # "blue    is sky the"  # s.split()
//     # "blue is sky the"  # s.split(' ')
//     list1.reverse()
//     s2 = " ".join(list1)
//     return s2
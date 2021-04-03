// jz34: 第一个只出现一次的字符
/* C++解法：使用vec<int>
    vector<int> vec(128);
    for(int i=0; i<s.size(); i++){  //***i<s.size()写成了i<s.size()-1
        vec[s[i]]++;
    }
    for(int i=0; i<s.size(); i++){
        if(vec[s[i]]==1)
            return i;
    }        
    return -1;        
}
/*


/* C++解法：使用map<char, int>
int FirstNotRepeatingChar(string s) {
    map<char, int> m;
    int len = s.size();
    for(int i=0; i<s.size(); i++){
        m[s[i]]++;
    }
    for(int i=0; i<s.size(); i++){
        if(m[s[i]]==1)
            return i;
    }
    return -1;
}
/*


/* python解法：使用str1.count(char)函数
def FirstNotRepeatingChar(self, s):
    for i in range(len(s)):
        if s.count(s[i])==1:
            return i
    return -1
/*
// jz47: 求1+2+3+...+n
// 思路1：
// summation formula (1+n)n/2
int Sum_Solution(int n) {
    return n*(n+1)/2;
}

// 思路2：递归recursion
int Sum_Solution(int n) {
    if(n==1)
        return 1;
    else
        return n + Sum_Solution(n-1);
}

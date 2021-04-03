// jz7: Fibonacci数列
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int Fibonacci(int n) {
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int a=0, b=1, c;
    for(int i=2; i<=n; i++){
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}
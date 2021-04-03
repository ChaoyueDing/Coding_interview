// jz8: jump floor
// 时间复杂度：O(n)
// 空间复杂度：O(1)
int jumpFloor(int number) {
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    int a = 2;
    int b = 1;
    int c = 0;
    for(int i=number-3; i>=0; i--)
    {
        c=a+b;
        b=a;
        a=c;
    }
    return a;
}
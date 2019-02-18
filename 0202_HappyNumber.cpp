/*
202.快乐数
编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 
输入: 19
输出: true
解释: 
1*1 + 9*9 = 82
8*8 + 2*2 = 68
6*6 + 8*8 = 100
1*1 + 0*0 + 0*0 = 1

作者：syt
日期：2019-02-18
*/

class Solution {
public:
    int sum(int n)
    {
        int num = 0;
        while(n)
        {
            int tmp = n%10;
            num = num+tmp*tmp;
            n = n/10;
        }
        return num;
    }
    bool isHappy(int n) {
        while(n != 1)
        {
            n = sum(n);
            if(n == 4)
                return false;
        }
        return true;
    }
};
/*
367.有效的完全平方数
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。

示例 1：
输入：16
输出：True

示例 2：
输入：14
输出：False

作者：syt
日期：2018-12-21

思路：二分查找
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0)
            return false;
        if(num == 1)
            return true;
        long start = 0, end = num/2;
        while(start <= end)
        {
            long mid = (start + end)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid > num)
                end = mid-1;
            else
                start = mid+1;
        }
        return false;
    }
};
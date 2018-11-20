/*
231.2的幂
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:
输入: 1
输出: true
解释: 20 = 1

示例 2:
输入: 16
输出: true
解释: 24 = 16

示例 3:
输入: 218
输出: false

作者：syt
日期：2018-11-20

思路：当 n 是2的幂时，n的二进制中只有一位为 1，其余都为 0，若 n&(n-1) 为0，则表示n是2的幂，反之则不是2的幂
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0 && !(n & (n-1)))
            return true;
        return false;
    }
};
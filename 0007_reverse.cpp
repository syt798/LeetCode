/*
7.整数反转
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21

作者：syt
日期：2018-12-28
*/

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if(x < 0)
        {
            isNeg = true;
            x *= -1;
        }
        string data = to_string(x);
        string max = to_string(INT_MAX);
        int start = 0, end = data.length() - 1;
        while(start < end)
        {
            char tmp = data[start];
            data[start] = data[end];
            data[end] = tmp;
            ++start;
            --end;
        }
        if(data.length() == max.length())
        {
            if(data > max)
                return 0;
        }
        if(data.length() > max.length())
            return 0;
        

        if(isNeg)
            return -1 * atoi(data.c_str());
        else
            return atoi(data.c_str());
        
    }
};
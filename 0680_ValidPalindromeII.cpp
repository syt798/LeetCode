/*
680.验证回文字符串II
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:
输入: "aba"
输出: True

示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。

作者:syt
日期：2018-01-15
*/

class Solution {
public:
    bool isPalindrome(string s, int index)
    {
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            if(i == index)
            {
                i++;
                continue;
            }
            if(j == index)
            {
                j--;
                continue;
            }
            if(s[i++] != s[j--])
                return false;
        }
        return true;
      
    }
    bool validPalindrome(string s) {
        int start = 0, end = s.length() - 1;
        while(start < end)
        {
            if(s[start] != s[end])
            {
                if(isPalindrome(s, start) || isPalindrome(s, end))
                    return true;
                else
                    return false;
            }
            start++;
            end--;
        }
        return true;
        
    }
};
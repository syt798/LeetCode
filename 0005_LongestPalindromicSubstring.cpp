/*
5.最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"

作者:syt
日期：2018-12-03
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            int len1 = expandAround(s, i, i);
            int len2 = expandAround(s, i, i+1);
            int len = max(len1, len2);
            if(len > end - start)
            {
                start = i - (len-1)/2;
                end = i + len/2;
            }
            
        }
        return s.substr(start, end-start+1);
    }
    int expandAround(string s, int left, int right)
    {
        while(left >= 0 && right < s.length() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return right-left-1;
    }
};

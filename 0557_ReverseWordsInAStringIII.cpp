/*
557.反转字符串中的单词III
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:
输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 

作者:syt
日期：2018-01-11
*/

class Solution {
public:
    static void reverse(string& s, int start, int end)
    {
        while(start < end)
        {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        bool isSpace = false;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                isSpace = true;
                end = i;
                reverse(s, start, end - 1);
                
            }
            else
            {
                if(isSpace)
                {
                    isSpace = false;
                    start = i;
                }
                
                if(i == s.length() - 1)
                    reverse(s, start, s.length() - 1);
            }
        }
        return s;
        
    }
};
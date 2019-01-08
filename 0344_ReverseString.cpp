/*
344.反转字符串
编写一个函数，其作用是将输入的字符串反转过来。

示例 1:
输入: "hello"
输出: "olleh"

示例 2:
输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"

作者:syt
日期：2018-01-08
*/

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
        return s;
    }
};
/*
537.复数乘法
给定两个表示复数的字符串。
返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。

示例 1:
输入: "1+1i", "1+1i"
输出: "0+2i"
解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。

示例 2:
输入: "1+-1i", "1+-1i"
输出: "0+-2i"
解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 

作者:syt
日期：2018-01-14
*/

class Solution {
public:
     static int convert(string s, int start, int n)
    {
        string tmp = s.substr(start, n);
        return atoi(tmp.c_str());
    }
    string complexNumberMultiply(string a, string b) {
        if(a.length() != 0 && b.length() != 0)
        {
      
            int end = a.find('+');
            int a_a = convert(a, 0, end);
            int a_b = convert(a, end + 1, a.length() - end);
            
            end = b.find('+');
            int b_c = convert(b, 0, end);
            int b_d = convert(b, end + 1, b.length() - end);
            
            return to_string(a_a * b_c - a_b * b_d) + "+" + to_string(a_b * b_c + a_a * b_d) + "i";
        }
        else
            return (a.length() == 0)? b : a;
    }
};
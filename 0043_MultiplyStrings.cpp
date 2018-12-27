/*
43.字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

作者：syt
日期：2018-12-27
*/

class Solution {
public:
    string twoStringAdd(string str1, string str2)
    {
        string result = "";
        int carry = 0;
        int i = str1.length()-1;
        int j = str2.length()-1;
        while(i >= 0 || j >= 0)
        {
            int x = 0;
            int y = 0;
            if(i >= 0)
            {
                x = str1[i]-'0';
                --i;
            }
            if(j >= 0)
            {
                y = str2[j]-'0';
                --j;
            }
            result = to_string((x+y+carry)%10) + result;
            carry = (x+y+carry)/10;       
        }
        if(carry > 0)
            result = to_string(carry) + result;
        return result;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string result = "";
        int zeroIndex = 0;
        for(int i = num2.length()-1; i >= 0; --i)
        {
            int tmp = num2[i]-'0';
            string num = "";
            int carry = 0;
            for(int j = num1.length()-1; j >= 0; --j)
            {
                int x = num1[j]-'0';
                num = to_string((x*tmp + carry)%10) + num;
                carry = (x*tmp+carry)/10;
            }
            if(carry > 0)
                num = to_string(carry) + num;
            string zeros(zeroIndex, '0');
            num += zeros;
            zeroIndex++;
            result = twoStringAdd(result, num);
        }
        return result;
    }
};
/*
6.Z字形变换
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
L   C   I   R
E T O E S I I G
E   D   H   N

之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：
string convert(string s, int numRows);

示例 1:
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

示例 2:
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
L     D     R
E   O E   I I
E C   I H   N
T     S     G

作者：syt
日期：2018-12-25

思路：用一个字符串数组保存每一行的字符串，遍历之后合并
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result = "";
        vector<string> data(numRows, "");
        bool flag = true;
        int index = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            data[index] += s.substr(i, 1);
            if(flag)
            {
                ++index;
            }
            else
            {
                --index;
            }
            
            if(index == numRows-1)
                flag = false;
            if(index == 0)
                flag = true;
        }
        
        for(int i = 0; i < data.size(); ++i)
            result += data[i];
        return result;
    }
};
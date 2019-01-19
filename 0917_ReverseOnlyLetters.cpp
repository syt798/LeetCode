/*
917.仅仅反转字母
给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。

示例 1：
输入："ab-cd"
输出："dc-ba"

示例 2：
输入："a-bC-dEf-ghIj"
输出："j-Ih-gfE-dCba"

示例 3：
输入："Test1ng-Leet=code-Q!"
输出："Qedo1ct-eeLg=ntse-

作者：syt
日期：2019-01-19
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.length()-1;
        while(i < j)
        {
            while(i < j && !isalpha(S[i]))
                ++i;
            while(i < j && !isalpha(S[j]))
                --j;
            if(i >= j)
                break;
            char tmp = S[i];
            S[i] = S[j];
            S[j] = tmp;
            ++i;
            --j;
        }
        return S;
    }
};
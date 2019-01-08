/*
22.括号生成
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

作者:syt
日期：2018-01-07
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate(ret, "", 0, 0, n);
        return ret;
    }
    
    void generate(vector<string> &ret, string str, int left, int right, int n)
    {
        if(left > n || right > n || right > left)
            return;
        if(left == n && right == n)
        {
            ret.push_back(str);
            return;
        }
        generate(ret, str + "(", left+1, right, n);
        generate(ret, str + ")", left, right+1, n);
        return;
    }
};
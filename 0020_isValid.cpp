/*
200.有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

作者:syt
日期：2018-12-05

*/

class Solution {
public:
    bool isValid(string s) {
        bool result = true;
        if(s.empty())
            return result;
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else
            {
                if(st.empty())
                {
                    result = false;
                    return result;
                }
                char tmp = st.top();
                if((tmp == '(' && s[i] == ')') || (tmp == '[' && s[i] == ']') || (tmp == '{' && s[i] == '}'))
                {
                    
                }
                else
                {
                    result = false;
                    return result;
                }
                st.pop();

            }
        }
        if(!st.empty())
            result = false;
        
        return result;
    }
};
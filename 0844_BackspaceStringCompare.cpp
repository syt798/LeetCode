/*
844.比较含退格的字符串
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

示例 3：
输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。

示例 4：
输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。

作者：syt
日期：2018-12-27
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string sTmp = "";
        string tTmp = "";
        for(int i = 0; i < S.length(); ++i)
        {
            if(S[i] == '#')
            {
                if(!sTmp.empty())
                    sTmp.erase(sTmp.length()-1, 1);

            }
            else
                sTmp += S.substr(i, 1);
        }
        for(int i = 0; i < T.length(); ++i)
        {
            if(T[i] == '#')
            {
                if(!tTmp.empty())
                    tTmp.erase(tTmp.length()-1, 1);

            }
            else
                tTmp += T.substr(i, 1);
        }
        
        return (sTmp == tTmp);
    }
};
/*
942.增减字符串匹配
给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
如果 S[i] == "I"，那么 A[i] < A[i+1]
如果 S[i] == "D"，那么 A[i] > A[i+1]

示例 1：
输出："IDID"
输出：[0,4,1,3,2]

示例 2：
输出："III"
输出：[0,1,2,3]

示例 3：
输出："DDI"
输出：[3,2,0,1]

作者：syt
日期：2019-01-18
*/

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ret(S.length()+1, 0);
        int number = 0;
        for(int i = 0; i < S.length(); ++i)
        {
            if(S[i] == 'I')
            {
                ret[i] = number++;
            }            
            else if(S[i] == 'D')
            {
                ret[i] = -1;
            }
        }
        ret[S.length()] = number++;
        for(int i = ret.size()-1; i >= 0; --i)
        {
            if(ret[i] == -1)
                ret[i] = number++;
        }
        return ret;
    }
};
/*
14.最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

作者:syt
日期：2018-12-10

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string minStr = "";
        string preSub = "";
        for(int i = 0; i < strs.size(); i++)
        {
            if(strs[i].length() > minStr.length())
                minStr = strs[i];
        }
        for(int i = 1; i <= minStr.length(); i++)
        {
            string sub = minStr.substr(0, i);
            bool isSub = true;
            for(int j = 0; j < strs.size(); j++)
            {
                string tmpSub = strs[j].substr(0, i);
                if(sub != tmpSub)
                {
                    isSub = false;
                    break;
                }
            }
            if(isSub)
                preSub = sub;
            else
                break;
                
        }
        return preSub;
    }
};
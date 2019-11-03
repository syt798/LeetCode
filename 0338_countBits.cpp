/*
338.比特位计数
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:
输入: 2
输出: [0,1,1]

示例 2:
输入: 5
输出: [0,1,1,2,1,2]

作者：syt
日期：2018-12-29
*/

class Solution {
public:
    
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; ++i)
        {
            int tmp = i;
            int count = 0;
            while(tmp)
            {
                tmp = tmp&(tmp-1);
                ++count;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
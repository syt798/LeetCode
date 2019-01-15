/*
674.最长连续递增序列
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:
输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 

示例 2:
输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。

作者:syt
日期：2018-01-15
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return 1;
        int ret = 1;
        int count = 1;
        for(int i = 0; i < nums.size()-1; ++i)
        {
            if(nums[i+1] > nums[i])
                ++count;
            else
            {
                if(count > ret)
                    ret = count;
                count = 1;
            }

        }
        if(count > ret)
            ret = count;
        return ret;
    }
};
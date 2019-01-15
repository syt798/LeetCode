/*
164.最大间距
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
如果数组元素个数小于 2，则返回 0。

示例 1:
输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。

示例 2:
输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。

作者:syt
日期：2018-01-15
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int ret = 0;
        if(nums.size() < 2)
            return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; ++i)
        {
            int dis = nums[i+1] - nums[i];
            if(dis > ret)
                ret = dis;
        }
        return ret;        
    }
};
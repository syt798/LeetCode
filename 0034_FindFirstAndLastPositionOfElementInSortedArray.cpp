/*
34.在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

作者：syt
日期：2018-12-19
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> loc(2,-1);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                if(loc[0] == -1)
                {
                    loc[0] = i;
                    loc[1] = i;
                }
                else
                    loc[1] = i;
            }
        }
        return loc;
    }
};
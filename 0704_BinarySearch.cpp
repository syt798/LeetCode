/*
704.二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

作者：syt
日期：2019-02-16
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = -1;
        int start = 0, end = nums.size()-1;
        while(start <= end)
        {
            int mid = (start+end)/2;
            if(nums[mid] == target)
            {
                ret = mid;
                break;
            }
            if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return ret;
    }
};
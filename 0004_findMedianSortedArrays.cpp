/*
4.寻找两个有序数组的中位数
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

作者:syt
日期：2018-11-30
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0;
        for(int i = 0; i < nums2.size(); ++i)
            nums1.push_back(nums2[i]);
        
        sort(nums1.begin(), nums1.end());
        if(nums1.size()%2 == 0)
            result = (nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2.0;
        else
            result = nums1[nums1.size()/2]; 
        
        return result;
    }
};
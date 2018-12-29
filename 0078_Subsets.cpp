/*
78.子集
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

示例:
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

作者：syt
日期：2018-12-29

思路：位运算
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = pow(2, nums.size());
        for(int i = 0; i < n; ++i)
        {
            vector<int> tmp;
            for(int j = 0; j < nums.size(); ++j)
            {
                if((1<<j)&i)
                    tmp.push_back(nums[j]);
            }
            
            result.push_back(tmp);
        }
        
        return result;
    }
};
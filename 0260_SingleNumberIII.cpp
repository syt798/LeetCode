/*
260.只出现一次的数字III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

示例 :
输入: [1,2,1,3,2,5]
输出: [3,5]

注意：
结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

作者：syt
日期：2018-12-20

思路：对vector 内容排序，比较相邻两个的值是否相同，不相同加入到 result 中，注意最后一个数的判断
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if(nums.empty())
            return result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-1)
        {
            if(nums[i] == nums[i+1])
            {
                i += 2;
            }
            else
            {
                result.push_back(nums[i]);
                i += 1;
            }
        }
        if(nums[nums.size()-1] != nums[nums.size()-2])
            result.push_back(nums[nums.size()-1]);
        return result;
    }
};
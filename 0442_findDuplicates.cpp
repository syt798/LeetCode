/*
442.数组中重复的数据
给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
找到所有出现两次的元素。

示例：
输入:
[4,3,2,7,8,2,3,1]
输出:
[2,3]

作者：syt
日期：2019-02-17
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        vector<int> data(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            data[nums[i]]++;
        }
        for(int i = 0; i < data.size(); ++i)
        {
            if(data[i] == 2)
                ret.push_back(i);
        }
        return ret;
    }
};
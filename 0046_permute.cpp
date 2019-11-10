/*

*/

class Solution {
public:

    //位置交换
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    void backTrackPermute(vector<vector<int>> &ret, vector<int> &nums, int index) {
        for (int i = index; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                swap(nums, i, j);
                backTrackPermute(ret, nums, i + 1);
                ret.push_back(nums);
                swap(nums, i, j);
            }            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        ret.push_back(nums);
        backTrackPermute(ret, nums, 0);
        return ret;
    }
};
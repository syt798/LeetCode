class Solution {
public:
    void backTrackCombine(vector<vector<int>> &ret, vector<int> &nums, vector<int> &curr, int index, int k) {
        if (curr.size() == k) {
            ret.push_back(curr);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backTrackCombine(ret, nums, curr, i + 1, k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> nums(n);
        vector<int> curr;
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        backTrackCombine(ret, nums, curr, 0, k);
        return ret;
    }
};
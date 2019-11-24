class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(sum < 0)
                sum = 0;
            sum += nums[i];
            maxSub = max(maxSub, sum);
        }
        return maxSub;
    }
};
//1、划分子问题：最后一步，从石头 i 跳到 n-1，最后一步跳跃的最大距离为 nums[i] + i >= n-1,
//      子问题：青蛙能不能跳到 石头 i 即 f[i] ?
//2、状态转移方程：f[j] =  f[i](0~i<=j) && (i + nums[i] >= j)
//3、初始条件和边界：f[0] = true，不需要考虑边界
//4、计算顺序，f[0,1,2,3,4]

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        int numsSize = nums.size();
        bool *dp = (bool *)malloc(sizeof(bool) * numsSize);
        dp[0] = true;
        for (int j = 1; j < numsSize; ++j) {
            dp[j] = false;
            for (int i = 0; i < j; ++i) {
                if (dp[i] && (i + nums[i]) >= j) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[numsSize - 1];  
    }
};

/*
动态规划，直接在原数组上进行操作，O（1）的额外空间
dp[i][j] = dp[i - 1][j - 1] + dp[i][j];

*/
class Solution {
public:
    int min(int a, int b) {
        return a > b ? b : a;
    }
    int minimumTotal(vector<vector<int>>& triangle) {                
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                } else if (j == triangle[i].size() - 1) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                } else {
                    triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
                }
            }
        }
        
        int ret = INT_MAX;
        int i = triangle.size() - 1;
        for (int j = 0; j < triangle[i].size(); ++j) {

             if (triangle[i][j] < ret) {
                 ret = triangle[i][j];
             }
        }
        return ret;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int n = matrix.size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n-i; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = tmp;
            }
        }
        for(int i = 0; i < n/2; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][j];
                matrix[n-i-1][j] = tmp;
            }
        }
    }
};
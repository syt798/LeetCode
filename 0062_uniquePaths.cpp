//1、划分子问题：最后一步走到（m-1，n-1），子问题 (m-2, n-1) + (m-1, n-2)
//2、转移方程 f[i][j] = f[i-1][j] + f[i][j-1]
//3、初始条件，边界  f[0][0] = 1
//              边界：i = 0， j = 0
//4、计算顺序f[0][0---m],f[1][]

class Solution {
public:
    int uniquePaths(int m, int n) {
        int steps[m][n]={0};
        for(int i = 0; i < n; ++i)
            steps[0][i] = 1;
        for(int i = 0; i < m; ++i)
            steps[i][0] = 1;
        
        
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                    steps[i][j] = steps[i-1][j] + steps[i][j-1];
            }
        }
        return steps[m-1][n-1];
    }
};
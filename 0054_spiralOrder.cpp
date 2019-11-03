/*
54.螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]

示例 2:
输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

作者:syt
日期：2018-01-17
*/

class Solution {
public:
    void print(vector<vector<int>> matrix, int rows, int cols, int start, vector<int>& ret)
    {
        int endX = cols-start-1;
        int endY = rows-start-1;
        
        for(int i = start; i <= endX; ++i)
            ret.push_back(matrix[start][i]);
        
        if(start < endY)
        {
            for(int i = start+1; i <= endY; ++i)
                ret.push_back(matrix[i][endX]);
        }
        
        if(start < endX && start < endY)
        {
            for(int i = endX-1; i >= start; --i)
                ret.push_back(matrix[endY][i]);
        }
        if(start < endX && start < endY-1)
        {
            for(int i = endY-1; i >= start+1; --i)
                ret.push_back(matrix[i][start]);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty())
            return ret;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        while(rows > start*2 && cols > start*2)
        {
            print(matrix, rows, cols, start, ret);
            ++start;
        }
        return ret;
    }
};
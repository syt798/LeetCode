/*
498.对角线遍历
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出:  [1,2,4,7,5,3,6,8,9]


作者:syt
日期：2018-12-05

思路：首先不考虑翻转的问题，确定对角线的起点位置 (0,0)->(1,0)->...->(m-1,0)->(m-1,1)->...->(m-1,n-1),从起始位置到边界位置遍历，设置翻转符，翻转每行的数据

*/

class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> data;
        if(matrix.empty())
            return data;
        int m = matrix.size(), n = matrix[0].size();
        int start_x = 0, start_y = 0;
        bool isreverse = false;
        
        while(start_x < m && start_y < n)
        {
            int i = start_x;
            int j = start_y;
            int index = data.size();
            while(i >= 0 && j < n)
            {
                data.push_back(matrix[i][j]);
                i--;
                j++;
            }
            if(isreverse)
            {
                reverse(data.begin()+index, data.end());
                isreverse = false;
            }
            else
                isreverse = true;
            
            if(start_x == (m-1))
                ++start_y;
            else
                ++start_x;
        }
        return data;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int row = 0; row < numRows; ++row)
        {
            vector<int> tmp;
            for(int col = 0; col <= row; ++col)
            {
                if(col == 0 || col == row)
                    tmp.push_back(1);
                else
                    tmp.push_back(result[row-1][col-1]+result[row-1][col]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
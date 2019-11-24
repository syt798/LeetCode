class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<vector<int>> data;
        for(int row = 0; row <= rowIndex; ++row)
        {
            vector<int> tmp;
            for(int col = 0; col <= row; ++col)
            {
                if(col == 0 || col == row)
                    tmp.push_back(1);
                else
                    tmp.push_back(data[row-1][col-1]+data[row-1][col]);
                
                if(row == rowIndex)
                    result = tmp;

            }
            data.push_back(tmp);
        }
        
        
        return result;
    }
};
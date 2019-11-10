class Solution {
public:
    bool colUniq(vector<vector<char>>& board, int rowIndex, int colIndex)
    {
        bool result = true;
        for(int row = 0; row < 9; ++row)
        {
            if(row == rowIndex)
                continue;
            if(board[row][colIndex] == board[rowIndex][colIndex])
                return false;
        }
        return result;
    }
    bool rowUniq(vector<vector<char>>& board, int rowIndex, int colIndex)
    {
        bool result = true;
        for(int col = 0; col < 9; ++col)
        {
            if(col == colIndex)
                continue;
            if(board[rowIndex][col] == board[rowIndex][colIndex])
                return false;
        }
        return result;
    }
    bool smallSudoku(vector<vector<char>>& board, int rowIndex, int colIndex)
    {
        bool result = true;
        
        int nRow = rowIndex / 3;
        int nCol = colIndex / 3;
        
        int rowStart = nRow * 3;
        int rowEnd = rowStart + 3;
        int colStart = nCol * 3;
        int colEnd = colStart + 3;
        
        for(; rowStart < rowEnd; ++rowStart)
        {
            for(colStart = nCol*3; colStart < colEnd; ++colStart)
            {
                if(rowStart == rowIndex && colStart == colIndex)
                    continue;
                if(board[rowStart][colStart] == board[rowIndex][colIndex])
                    return false;
            }
        }
        return result;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result = true;
        for(int row = 0; row < 9; ++row)
        {
            for(int col = 0; col < 9; ++col)
            {
                if(board[row][col] == '.')
                    continue;
                if(!colUniq(board, row, col))
                    return false;
                if(!rowUniq(board, row, col))
                    return false;
                if(!smallSudoku(board, row, col))
                    return false;
            }
        }
        return result;
    }
};
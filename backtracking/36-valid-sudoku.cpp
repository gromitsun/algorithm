class Solution {
    
    // indicators for rows, columns, and 3x3 divisions
    vector<int> rows = decltype(rows)(9, 0);
    vector<int> cols = decltype(cols)(9, 0);
    vector<vector<int>> divs = decltype(divs)(3, vector<int>(3, 0));
    
    // try to place one number on board @ (row, col)
    // return whether this placement is allowed
    inline bool place(char c, int row, int col)
    {
        // checker
        int x = 1 << (c - '1');
        
        // check row
        if (rows[row] & x)
        {
            return false;
        }
        
        // check column
        if (cols[col] & x)
        {
            return false;
        }
        
        // check 3x3
        if (divs[row/3][col/3] & x)
        {
            return false;
        }
        
        // update indicator
        rows[row] |= x;
        cols[col] |= x;
        divs[row/3][col/3] |= x;
        
        return true;
    }
    
    // check board validity
    inline bool check(vector<vector<char>>& board)
    {
        for (int row=0; row<9; row++)
        {
            for (int col=0; col<9; col++)
            {
                if (board[row][col] != '.' && !place(board[row][col], row, col))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        return check(board);
    }
};


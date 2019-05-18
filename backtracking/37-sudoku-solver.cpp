class Solution {
    // board
    vector<vector<char>> board;
    
    // indicators for rows, columns, and 3x3 divisions
    vector<int> rows = decltype(rows)(9, 0);
    vector<int> cols = decltype(cols)(9, 0);
    vector<vector<int>> divs = decltype(divs)(3, vector<int>(3, 0));
    
    // initialize board and indicators
    inline void initialize(vector<vector<char>>& board)
    {
        for (int row=0; row<9; row++)
        {
            for (int col=0; col<9; col++)
            {
                if (board[row][col] != '.')
                {
                    int x = 1 << (board[row][col] - '1');
                    rows[row] |= x;
                    cols[col] |= x;
                    divs[row/3][col/3] |= x;
                }
            }
        }
        
        swap(board, this->board);
    }
    
    // swap board back for return
    inline void finalize(vector<vector<char>>& board)
    {
        swap(board, this->board);
    }
    
    // check if we can place at this location
    inline bool isValid(char c, int row, int col)
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
        
        return true;
    }
    
    // place one number on board
    inline void place(char c, int row, int col)
    {
        // place on board
        board[row][col] = c;
        
        // update indicator
        int x = 1 << (c - '1');
        rows[row] |= x;
        cols[col] |= x;
        divs[row/3][col/3] |= x;
    }
    
    // remove one number from board
    inline void remove(char c, int row, int col)
    {
        // remove from board
        board[row][col] = '.';
        
        // update indicator
        int x = ~(1 << (c - '1'));
        rows[row] &= x;
        cols[col] &= x;
        divs[row/3][col/3] &= x;
    }
    
    // DFS
    inline bool dfs(int offset)
    {
        // // skip occupied board locations
        // while (offset < 81 && board[offset/9][offset%9] != '.')
        // {
        //     offset++;
        // }
        
        // found a solution
        if (offset == 81)
        {
            return true;
        }
        
        // row, col coords
        int row = offset / 9;
        int col = offset % 9;
        
        // skip occupied board locations
        if (board[row][col] != '.')
        {
            return dfs(offset + 1);
        }
        
        // iterate over all possible numbers
        for (char c='1'; c<='9'; c++)
        {            
            if (isValid(c, row, col))
            {
                // place one number on board
                place(c, row, col);
                // go to next position
                if(dfs(offset + 1))
                {
                    return true;
                }
                // remove the number from board
                remove(c, row, col);
            }
        }
        return false;
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize board and indicators
        initialize(board);
        // do DFS
        dfs(0);
        // swap board back for return
        finalize(board);
    }
};


class Solution {
    // solutions
    vector<vector<string>> ret;
    // board    
    vector<string> board;
    // current column
    int col = 0;
    // size of board
    int size;
    
    // create an empty board
    void initBoard(int n)
    {
        size = n;
        board.reserve(size);
        board.clear();
        
        for (int i=0; i<size; i++)
        {
            board.push_back(string(size, '.'));
        }
    }
    
    // check if we can place a queen at a certain coordinate
    inline bool isSafe(int row)
    {
        // check left
        for (int i=0; i<col; i++)
        {
            if (board[row][i] == 'Q')
            {
                return false;
            }
        }
        
        // check upper diagonal
        for (int i=1; i<=min(col,row); i++)
        {
            if (board[row-i][col-i] == 'Q')
            {
                return false;
            }
        }
        
        // check lower diagonal
        for (int i=1; i<=min(col,size-row-1); i++)
        {
            if (board[row+i][col-i] == 'Q')
            {
                return false;
            }
        }
        
        return true;
    }
    
    // DFS to find solutions
    void dfs()
    {
        
        // found a solution
        if (col == size)
        {
            ret.push_back(board);
            return;
        }
        
        for (int row = 0; row < size; row++)
        {
            if (isSafe(row))
            {
                
                // place a queen
                board[row][col] = 'Q';
                // continue with next column
                col++;
                dfs();
                col--;
                // reset board
                board[row][col] = '.';
            }
        }
        // no solutions found
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        
        // create empty board
        initBoard(n);
        
        // do DFS
        dfs();
        
        return ret;
        
    }
};


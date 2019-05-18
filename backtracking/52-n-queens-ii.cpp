lass SolutionBit {
    
    // number of solutions
    int ret = 0;
    // one solution
    // each int is one row
    // each bit in int is one loc on board
    vector<int> board;
    // board size
    int size;    
    // current column -- we count col from last bit in int
    int col = 0;
    
    // initialize board
    void initBoard(int n)
    {
        size = n;
        board = vector<int>(size, 0);
    }
    
    // check if we can place a queen
    inline bool isSafe(int row)
    {
        // check left
        if (board[row])
        {
            return false;
        }
        
        // check upper diagonal
        for (int i=1; i<=min(col,row); i++)
        {
            if (board[row-i] & (1 << (col-i)))
            {
                return false;
            }
        }
        
        // check lower diagonal
        for (int i=1; i<=min(col,size-row-1); i++)
        {
            if (board[row+i] & (1 << (col-i)))
            {
                return false;
            }
        }
        
        return true;
    }
    
    // DFS
    void dfs()
    {
        
        // found a solution
        if (col == size)
        {
            ret++;
            return;
        }
        
        for (int row = 0; row < size; row++)
        {
            if (isSafe(row))
            {
                
                // place a queen
                board[row] |= 1 << col;
                // continue with next column
                col++;
                dfs();
                col--;
                // reset board
                board[row] ^= 1 << col;
            }
        }
        // no solutions found
    }
    
public:
    int totalNQueens(int n) {
        // create empty board
        initBoard(n);
        
        // do DFS
        dfs();
        
        return ret;
    }
};


/* Regular vectors */
class SolutionVector {
    
    // number of solutions
    int ret = 0;
    // one solution
    // each int is one row
    // each bit in int is one loc on board
    vector<vector<char>> board;
    // board size
    int size;    
    // current column -- we count col from last bit in int
    int col = 0;
    
    // initialize board
    void initBoard(int n)
    {
        size = n;
        board = vector<vector<char>>(size, vector<char>(size, 0));
    }
    
    // check if we can place a queen
    inline bool isSafe(int row)
    {
        // check left
        for (int i=0; i<col; i++)
        {
            if (board[row][i])
            {
                return false;
            }
        }
        
        // check upper diagonal
        for (int i=1; i<=min(col,row); i++)
        {
            if (board[row-i][col-i])
            {
                return false;
            }
        }
        
        // check lower diagonal
        for (int i=1; i<=min(col,size-row-1); i++)
        {
            if (board[row+i][col-i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    // DFS
    void dfs()
    {
        
        // found a solution
        if (col == size)
        {
            ret++;
            return;
        }
        
        for (int row = 0; row < size; row++)
        {
            if (isSafe(row))
            {
                
                // place a queen
                board[row][col] = 1;
                // continue with next column
                col++;
                dfs();
                col--;
                // reset board
                board[row][col] = 0;
            }
        }
        // no solutions found
    }
    
public:
    int totalNQueens(int n) {
        // create empty board
        initBoard(n);
        
        // do DFS
        dfs();
        
        return ret;
    }
};


typedef SolutionBit Solution;


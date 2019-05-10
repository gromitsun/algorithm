class Solution {
    // global index on word
    int i;
    
    bool dfs(vector<vector<char>>& board, string& word, int row, int col)        
    {
        
        // we hit the edge
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        {
            return false;
        }
        
        char& c = board[row][col];
        
        // we hit a used char
        if (!c)
        {
            return false;
        }
        
        if (c == word[i])
        {
            // all matched
            if (i == word.size() - 1)
            {
                return true;
            }
            
            // temporarily mask the current char on board
            c = 0;
            // increase word index
            i++;
            
            // check four directions
            bool ret = dfs(board, word, row-1, col) || dfs(board, word, row, col-1) || dfs(board, word, row+1, col) || dfs(board, word, row, col+1);
            
            // revert i and board element
            i--;
            c = word[i];
            
            return ret;
        }
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        // interative over start point
        for (int row=0; row<board.size(); row++)
        {
            for (int col=0; col<board[0].size(); col++)
            {
                if(dfs(board, word, row, col))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};


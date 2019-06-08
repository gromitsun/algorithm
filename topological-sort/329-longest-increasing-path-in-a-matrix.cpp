/* Runtime: 40 ms, faster than 92.09% of C++ online submissions for Longest Increasing Path in a Matrix. */
class Solution {
    
    // dynamic programming memoization matrix
    // stores the max increasing path starting from a matrix element
    vector<vector<int>> dp;
    
    // dimension of matrix
    int n, m;
    
    // max increasing path length
    int max_len = 0;
    
    // initialize dp matrix
    inline void init(vector<vector<int>>& matrix)
    {
        n = matrix.size();
        m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, 0));
    }
    
    // do dfs to get longest increasing path
    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if (dp[i][j])
        {
            return dp[i][j];
        }
        
        // get max path length excluding the current element
        if (i > 0 && matrix[i-1][j] > matrix[i][j])
        {
            dp[i][j] = max(dfs(matrix, i-1, j), dp[i][j]);
        }
        
        if (i < n-1 && matrix[i+1][j] > matrix[i][j])
        {
            dp[i][j] = max(dfs(matrix, i+1, j), dp[i][j]);
        }
        
        if (j > 0 && matrix[i][j-1] > matrix[i][j])
        {
            dp[i][j] = max(dfs(matrix, i, j-1), dp[i][j]);
        }
        
        if (j < m-1 && matrix[i][j+1] > matrix[i][j])
        {
            dp[i][j] = max(dfs(matrix, i, j+1), dp[i][j]);
        }
        
        // add current element to path length
        dp[i][j]++;
        
        return dp[i][j];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        
        init(matrix);
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                max_len = max(max_len, dfs(matrix, i, j));
            }
        }
        
        return max_len;
    }
};


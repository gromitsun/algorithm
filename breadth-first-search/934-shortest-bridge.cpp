class Solution {
    
    pair<int, int> find_one(vector<vector<int>>& A)
    {
        int n = A.size();
        int m = A[0].size();
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (A[i][j])
                {
                    return {i, j};
                }
            }
        }
        
        return {-1, -1};
    }
    
public:
    int shortestBridge(vector<vector<int>>& A) {
        
        int n = A.size();
        int m = A[0].size();
        
        
        vector<vector<char>> visited(n, vector<char>(m, 0));
        
        // find a 1
        int r0 = -1;
        int c0 = -1;
        
        for (int i=0; i<n && r0 < 0; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (A[i][j])
                {
                    r0 = i;
                    c0 = j;
                    break;
                }
            }
        }
        
        // DFS to find one of the islands
        deque<int> islr;
        deque<int> islc;
        deque<int> rows;
        deque<int> cols;
        rows.push_back(r0);
        cols.push_back(c0);
        
        while (!rows.empty())
        {
            int i = rows.back();
            int j = cols.back();
            rows.pop_back();
            cols.pop_back();
            
            islr.push_back(i);
            islc.push_back(j);
            
            // check four directions
            if (i > 0)
            {
                if (!visited[i-1][j])
                {
                    if (A[i-1][j])
                    {
                        rows.push_back(i-1);
                        cols.push_back(j);
                    }
                    visited[i-1][j] = 1;
                }
            }
            
            if (j > 0)
            {
                if (!visited[i][j-1])
                {
                    if (A[i][j-1])
                    {
                        rows.push_back(i);
                        cols.push_back(j-1);
                    }
                    visited[i][j-1] = 1;
                }
            }
            
            if (i < n - 1)
            {
                if (!visited[i+1][j])
                {
                    if (A[i+1][j])
                    {
                        rows.push_back(i+1);
                        cols.push_back(j);
                    }
                    visited[i+1][j] = 1;
                }
            }
            
            if (j < m - 1)
            {
                if (!visited[i][j+1])
                {
                    if (A[i][j+1])
                    {
                        rows.push_back(i);
                        cols.push_back(j+1);
                    }
                    visited[i][j+1] = 1;
                }
            }
        }
        
        // reset visited
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                visited[i][j] = 0;
            }
        }
        
        for (int i=0; i<islr.size(); i++)
        {
            visited[islr[i]][islc[i]] = 1;
        }
        
        // BFS to find the next island
        int len = 0;
        int n_current = islr.size();
        int n_next = 0;
        while (!islr.empty())
        {
            int i = islr.front();
            int j = islc.front();
            islr.pop_front();
            islc.pop_front();
            n_current--;            
            
            // check four directions
            if (i > 0)
            {
                if (!visited[i-1][j])
                {
                    if (A[i-1][j])
                    {
                        return len;
                    }
                    islr.push_back(i-1);
                    islc.push_back(j);
                    n_next++;
                    visited[i-1][j] = 1;
                }
            }
            
            if (j > 0)
            {
                if (!visited[i][j-1])
                {
                    if (A[i][j-1])
                    {
                        return len;
                    }
                    islr.push_back(i);
                    islc.push_back(j-1);
                    n_next++;
                    visited[i][j-1] = 1;
                }
            }
            
            if (i < n - 1)
            {
                if (!visited[i+1][j])
                {
                    if (A[i+1][j])
                    {
                        return len;
                    }
                    islr.push_back(i+1);
                    islc.push_back(j);
                    n_next++;
                    visited[i+1][j] = 1;
                }
            }
            
            if (j < m - 1)
            {
                if (!visited[i][j+1])
                {
                    if (A[i][j+1])
                    {
                        return len;
                    }
                    islr.push_back(i);
                    islc.push_back(j+1);
                    n_next++;
                    visited[i][j+1] = 1;
                }
            }
            
            // move to the next level?
            if (n_current == 0)
            {
                swap(n_current, n_next);
                len++;
            }
        }
        
        return len;
    }
};


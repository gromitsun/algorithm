ass Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        if (matrix.empty())
            return matrix;
        
        if (matrix[0].empty())
            return matrix;
        
        // queue for BFS
        queue<int> rows;
        queue<int> cols;
        
        // sizes
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        // initialize queue with indices of 0's
        for (int i=0; i<matrix.size(); i++)
        {
            for (int j=0; j<matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.push(i);
                    cols.push(j);
                }
                else
                {
                    matrix[i][j] = -1;
                }
            }
        }
        
        // BFS
        while (!rows.empty())
        {
            int i = rows.front();
            int j = cols.front();
            rows.pop();
            cols.pop();
            
            // check elements on nsew
            if (i > 0)
            {
                if (matrix[i-1][j] < 0)
                {
                    matrix[i-1][j] = matrix[i][j] + 1;
                    rows.push(i-1);
                    cols.push(j);
                }
            }
            
            if (j > 0)
            {
                if (matrix[i][j-1] < 0)
                {
                    matrix[i][j-1] = matrix[i][j] + 1;
                    rows.push(i);
                    cols.push(j-1);
                }
            }
            
            if (i < n - 1)
            {
                if (matrix[i+1][j] < 0)
                {
                    matrix[i+1][j] = matrix[i][j] + 1;
                    rows.push(i+1);
                    cols.push(j);
                }
            }
            
            if (j < m - 1)
            {
                if (matrix[i][j+1] < 0)
                {
                    matrix[i][j+1] = matrix[i][j] + 1;
                    rows.push(i);
                    cols.push(j+1);
                }
            }
        }
        
        return matrix;
        
    }
};


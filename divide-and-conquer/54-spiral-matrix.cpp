class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        if (matrix.empty())
        {
            return ret;
        }
        
        
        int nrow = matrix.size(), ncol = matrix[0].size();
        int n = nrow * ncol;
        ret.reserve(nrow * ncol);
        
        // row and col bounds
        int rlow = 0, clow = 0;
        int rhigh = nrow - 1, chigh = ncol - 1;
        
        // direction
        char d = 0;
        
        // iterate spirally
        while (ret.size() < n)
        {
            if (d == 0)
            {
                for (int i=clow; i<=chigh; i++)
                {
                    ret.push_back(matrix[rlow][i]);
                }
                rlow++;
                d = 1;
            }
            else if (d == 1)
            {
                for (int i=rlow; i<=rhigh; i++)
                {
                    ret.push_back(matrix[i][chigh]);
                }
                chigh--;
                d = 2;
            }
            else if (d == 2)
            {
                for (int i=chigh; i>=clow; i--)
                {
                    ret.push_back(matrix[rhigh][i]);
                }
                rhigh--;
                d = 3;
            }
            else if (d == 3)
            {
                for (int i=rhigh; i>=rlow; i--)
                {
                    ret.push_back(matrix[i][clow]);
                }
                clow++;
                d = 0;
            }
        }
        
        return ret;
    }
};


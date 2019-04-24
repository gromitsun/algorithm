class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // check if matrix is empty
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        // check if target is smaller than the smallest in matrix
        if (target < matrix[0][0])
            return false;
        
        // search last element <= target in the first column
        int l = 0, r = matrix.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (matrix[m][0] == target)
            {
                return true;
            }
            else if (matrix[m][0] < target)
            {
                l = m + 1;
            }
            else 
            {
                r = m;
            }
        }
        
        // search target in row m
        vector<int>& row = matrix[l-1];
        l = 0;
        r = row.size();
        
        while(l < r)
        {
            int m = l + (r - l) / 2;
            if (row[m] == target)
            {
                return true;
            }
            else if (row[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        return false;        
    }
};


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        
        // row and col bounds
        int low = 0, high = n - 1;
        
        // direction
        char d = 0;
        
        // number to put in matrix
        int x = 1;
        
        // iterate spirally
        while (low <= high)
        {
            if (d == 0)
            {
                for (int i=low; i<=high; i++)
                {
                    ret[low][i] = x++;
                }
                d = 1;
            }
            else if (d == 1)
            {
                for (int i=low+1; i<high; i++)
                {
                    ret[i][high] = x++;
                }
                d = 2;
            }
            else if (d == 2)
            {
                for (int i=high; i>low; i--)
                {
                    ret[high][i] = x++;
                }
                d = 3;
            }
            else
            {
                for (int i=high; i>low; i--)
                {
                    ret[i][low] = x++;
                }
                high--;
                low++;
                d = 0;
            }
        }
        return ret;
    }
};


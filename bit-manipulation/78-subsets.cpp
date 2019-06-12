/* Runtime: 4 ms, faster than 99.39% of C++ online submissions for Subsets.
 * Memory Usage: 9 MB, less than 86.83% of C++ online submissions for Subsets. 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // total number of subsets (2^nums.size())
        int n = 1 << nums.size();
        // result
        vector<vector<int>> res(n, vector<int>());
        
        // using one int to represent the subset
        // each bit of the int indicates whether
        // we choose this element or not in the subset
        for (int i=0; i<n; i++)
        {
            int j = 0;
            while (i >> j)
            {
                if (i & (1 << j))
                {
                    res[i].push_back(nums[j]);
                }
                j++;
            }
        }
        
        return res;
    }
};



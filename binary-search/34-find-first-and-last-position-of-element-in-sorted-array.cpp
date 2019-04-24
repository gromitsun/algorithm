class Solution {
    
    // Given a sorted array, search the first occurrence of target between indices l and r
    // and return the index of the first occurrence
    int searchFirst(vector<int>& nums, int l, int r, int target)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        return l;
    }
    
    // Given a sorted array, search the last occurrence of target between indices l and r
    // and return the index of the last occurrence
    int searchLast(vector<int>& nums, int l, int r, int target)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] > target)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        
        return l - 1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res;
        res.reserve(2);
        
        // Edge case: empty input
        if (nums.empty())
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        int l = 0, r = nums.size(), m;
        
        // Do binary search until nums[m] == target
        // and l <= first, r > last
        while (l < r)
        {            
            m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                // Find first occurrence between l and m
                res.push_back(searchFirst(nums, l, m, target));
                // Find last occurrence between m and r
                res.push_back(searchLast(nums, m, r, target));
                return res;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else  // nums[m] > target
            {
                r = m;
            }            
        }
        
        // target not found
        res.push_back(-1);
        res.push_back(-1);
        return res;
        
    }
};


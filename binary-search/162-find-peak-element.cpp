class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // do a binary search to find a peak element
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m == 0 || nums[m] > nums[m-1])
            {
                // case 1: peak -- return index
                if (m == nums.size() - 1 || nums[m] > nums[m+1])
                {
                    return m;
                }
                // case 2: descending -- move right
                l = m + 1;
            }
            // case 3: ascending or local minimum -- move left
            // (in the case of a local minimum we can move left or right)
            else
            {
                r = m;
            }
        }
        
        // we'll never reach here
        throw "Program bug!";
    }
};


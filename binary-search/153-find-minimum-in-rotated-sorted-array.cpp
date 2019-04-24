class Solution {
public:
    int findMin(vector<int>& nums) {
        // check if array is sorted (unrotated)
        if (nums.front() <= nums.back())
            return nums.front();
        
        // do binary search
        int l = 0, r = nums.size();
        
        while (l < r)
        {
            int m = l + (r - l) / 2;
            // find partition b/w > nums.back() and <= nums.back()
            if (nums[m] > nums.back())
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        
        return nums[l];
    }
};


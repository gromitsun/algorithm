class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // check empty input
        if (nums.empty())
            return false;
        
        // do binary search
        int l = 0, r = nums.size();
        
        // case A: target > last -- target before pivot
        if (target > nums.back())
        {
            while (l < r)
            {
                int m = l + (r - l) / 2;
                // exit condition: found target
                if (nums[m] == target)
                {
                    return true;
                }
                
                // case 0: mid == last
                if (nums[m] == nums.back())
                {
                    // elements in [l, m] are same values -- keep right half
                    if (nums[m] != nums[r-1])
                    {
                        l = m + 1;
                    }
                    // elements in [m, r-1] are same values -- keep left half
                    else if (nums[m] != nums[l])
                    {
                        r = m;
                    }
                    // nums[l] == nums[m] == nums[r-1] -- cannot decide left/right
                    // however, we can safely exclude nums[l] and nums[r-1]
                    else
                    {
                        l++;
                        r--;
                    }
                }
                // case 1: mid < last < target or last < target < mid -- keep left half
                else if (nums[m] > target || nums[m] < nums.back())
                {
                    r = m;
                }
                // case 2: last < mid < target -- keep right half
                else
                {
                    l = m + 1;
                }
            }
        }
        // case B: target <= last -- target after pivot
        else
        {
            while (l < r)
            {
                int m = l + (r - l) / 2;
                // exit condition: found target
                if (nums[m] == target)
                {
                    return true;
                }
                
                // case 0: mid == last
                if (nums[m] == nums.back())
                {
                    // elements in [l, m] are same values -- keep right half
                    if (nums[m] != nums[r-1])
                    {
                        l = m + 1;
                    }
                    // elements in [m, r-1] are same values -- keep left half
                    else if (nums[m] != nums[l])
                    {
                        r = m;
                    }
                    // nums[l] == nums[m] == nums[r-1] -- cannot decide left/right
                    // however, we can safely exclude nums[l] and nums[r-1]
                    else
                    {
                        l++;
                        r--;
                    }
                }
                // case 1: mid < target <= last or target <= last < mid -- keep right half
                else if (nums[m] < target || nums[m] > nums.back())
                {
                    l = m + 1;
                }
                // case 2: target < mid < last -- keep left half
                else
                {
                    r = m;
                }
            }
        }
        
        return false;
    }
};


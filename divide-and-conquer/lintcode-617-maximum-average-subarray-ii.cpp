class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        
        // max average found so far
        double max_so_far = 0;
        
        // initialize max_so_far using first k numbers
        for (int i=0; i<k; i++)
        {
            max_so_far += (double)(nums[i]) / k;
        }
        
        // max average ending here
        double max_ending_here = max_so_far;
        // running average of k numbers ending here
        double ave_k_ending_here = max_so_far;
        // counter for number of elements included in max_ending_here
        int n = k;
        
        // dynamic programming to update the above loop invariants
        for (int i=k; i<nums.size(); i++)
        {
            ave_k_ending_here = ave_k_ending_here + (double)(nums[i] - nums[i-k]) / k;
            max_ending_here += (nums[i] - max_ending_here) / (++n);
            if (max_ending_here < ave_k_ending_here)
            {
                max_ending_here = ave_k_ending_here;
                n = k;
            }
            
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
            }
        }
        
        return max_so_far;
    }
};


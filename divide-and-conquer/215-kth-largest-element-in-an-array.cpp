class SolutionQS {
    
    // do a tailored version of quick sort 
    // to sort the array in descending order
    int quickSort(vector<int>& nums, int k) noexcept
    {
        // here we convert k to zero-based indexing for performance
        k--;

        // left and right bounds of section
        int l = 0, r = nums.size();

        while (l < r)
        {
            // pick the first element in section (nums[l]) as the pivot
            // and partition around it
            // p -- last of all visited elements that > the pivot -- this is where the pivot should be as of now
            // i -- current element being visited
            int p = l;
            for (int i=l+1; i<r; i++)
            {
                if (nums[i] > nums[l])
                {
                    swap(nums[++p], nums[i]);
                }
            }
            swap(nums[l], nums[p]);

            // check if we have found the solution
            if (p == k)
            {
                return nums[p];
            }

            // k-th largest on the left of pivot
            if (p > k)
            {
                r = p;
            }
            // k-th largest on the right of pivot
            else
            {
                l = p+1;
            } 
        }

        throw "Program bug: This line should be unreachable";
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) noexcept {
        return quickSort(nums, k);
    }
};

/* Using STL std::nth_element */
class SolutionSTL {
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        nth_element(nums.begin(), nums.begin()+k, nums.end(), greater<>());
        return nums[k];
    }
};


// typedef SolutionSTL Solution;
typedef SolutionQS Solution;


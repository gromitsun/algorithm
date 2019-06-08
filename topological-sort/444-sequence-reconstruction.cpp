/* LintCode runtime: 150 ms. Beats 99.80% */
class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here
        
        int n = org.size();
        
        // order of the integers in org
        vector<int> ord(n, 0);
        
        // is there a sequence for each adjacent pair?
        vector<bool> hasSeq(n, false);
        
        // org -> ord
        for (int i=0; i<n; i++)
        {
            ord[org[i]-1] = i;
        }
        
        // check if all seqs are consistent with the order in org
        for (auto& seq : seqs)
        {
            if (seq.empty())
            {
                continue;
            }
            
            // order of previous integer in seq
            int prev = -1;
            
            for (int x : seq)
            {
                // check for out-of-range numbers
                if (x < 1 || x > n)
                {
                    return false;
                }
                
                // order of current integer in seq
                int curr = ord[x-1];
                
                // first number in seq
                if (prev < 0)
                {
                    if (curr == 0)
                    {
                        hasSeq[curr] = true;
                    }
                    prev = curr;
                }
                else if (curr < prev)
                {
                    return false;
                }
                else if (curr - prev == 1)
                {
                    hasSeq[curr] = true;
                    prev = curr;
                }
            }
        }
        
        // check if all adjacent pairs are marked
        for (bool x : hasSeq)
        {
            if (!x)
            {
                return false;
            }
        }
        
        return true;
    }
};


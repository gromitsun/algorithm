class Solution {
    
    // solution
    vector<int> ret;
    
    // given the first two numbers 
    // check if they can make a Fibonacci sequence out of s
    inline bool isValid(string& s, int start)
    {
        // index in string s
        int i = start;
        // index in ret
        int j = 0;
        while (i < s.size())
        {
            // check overflow
            if (INT_MAX - ret[j] < ret[j+1])
            {
                return false;
            }
            // sum of previous two
            int sum = ret[j] + ret[j+1];
            // convert to string
            string s1 = to_string(sum);
            // check if we have a match in string
            if (s1.size() <= s.size() - start && s.substr(i, s1.size()) == s1)
            {
                // found a match, put it into ret
                ret.push_back(sum);
                i += s1.size();
                j++;                
            }
            else
            {
                // no match, delete all results except the first two
                ret.resize(2);
                return false;
            }
        }
        return true;
    }
    
public:
    vector<int> splitIntoFibonacci(string S) {
        
        // first number
        for (int i = 1; i <= S.size() - 2; i++)
        {
            string s1 = S.substr(0, i);
            // if it starts with '0', then it has to be 0
            if (s1[0] == '0' && s1.size() > 1)
            {
                break;
            }
            
            try
            {
                ret.push_back(stoi(s1));
            }
            catch (std::out_of_range)
            {
                break;
            }
            
            // second number
            for (int j = 1; j <= S.size() - i - 1; j++)
            {
                string s2 = S.substr(i, j);
                // if it starts with '0', then it has to be 0
                if (s2[0] == '0' && s2.size() > 1)
                {
                    break;
                }
                
                try
                {
                    ret.push_back(stoi(s2));
                }
                catch (std::out_of_range)
                {
                    break;
                }
                
                // check if we can find a solution with the first two numbers
                if (isValid(S, i + j))
                {
                    return ret;
                }
                ret.pop_back();
            }
            ret.pop_back();
        }
        
        return ret;        
    }
};


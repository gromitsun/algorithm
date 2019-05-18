class Solution {
    
    // ip component counter
    int n = 0;
    
    // results
    vector<string> ret;
    
    // holder for one ip
    vector<unsigned char> ip{0, 0, 0, 0};
    
    static inline bool isValid(int x)
    {
        return x < 256 && x >= 0;
    }
    
    
    // DFS
    void dfs(string& s, int start)
    {
        
        // found a candidate
        if (n == 4)
        {
            string candidate = to_string(ip[0]) + "." + to_string(ip[1]) + "." 
                               + to_string(ip[2]) + "." + to_string(ip[3]);
            
            // check if found a true solution
            if (candidate.size() == s.size() + 3)
            {
                ret.push_back(candidate);
            }
            return;
        }
        
        // iterate over digits from 'start'
        for (int i=start+1; i<=min(start+3, (int)s.size()); i++)
        {
            int x = stoi(s.substr(start, i-start));
            if (isValid(x))
            {
                ip[n] = x;
                
                // next component
                n++;
                dfs(s, i);
                n--;
            }
        }
    }
    
    
public:
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return ret;
    }
};


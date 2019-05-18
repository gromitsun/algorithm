// Backtracking
class SolutionBT {
    
    string s;
    string p;
    
    inline void init(string &s, string& p)
    {
        swap(s, this->s);
        swap(p, this->p);
    }
    
    bool dfs(int is, int ip)
    {
        // check if we have found a match
        if (ip == p.size())
        {
            // all characters in s are matched
            if (is == s.size())
            {
                return true;
            }
            // patterns used up, char's left in s
            return false;
        }
        
        // s used up, p has remainings
        if (is == s.size())
        {
            if (ip == p.size() - 1 || p[ip+1] != '*')
            {
                return false;
            }
            return dfs(is, ip+2);
        }
        
        // next char in p != '*'
        if (ip == p.size() - 1 || p[ip+1] != '*')
        {
            return (p[ip] == '.' || p[ip] == s[is]) && dfs(is+1, ip+1);
        }
        
        // next char in p == '*'
        for (int n=0; n<=s.size()-is; n++)
        {
            if (n == 0 || p[ip] == '.' || p[ip] == s[is+n-1])
            {
                if (dfs(is+n, ip+2))
                {
                    return true;
                }
            }
            else
            {
                break;
            }
        }
        return false; 
    }
    
public:
    bool isMatch(string s, string p) {
        init(s, p);
        return dfs(0, 0);
    }
};

// Dynamic programming
class SolutionDP {
    
public:
    bool isMatch(string s, string p) {
        
        // memoization array
        vector<vector<bool>> dp = decltype(dp)(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        
        // prevailing '*' patterns can match an empty string
        for (int j=2; j<=p.size(); j+=2)
        {
            if(p[j-1] == '*')
            {
                dp[0][j] = true;
            }
            else
            {
               break; 
            }
        }
        
        // main DP loops
        for (int i=1; i<=s.size(); i++)
        {
            for (int j=1; j<=p.size(); j++)
            {
                if (p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j];
                }
                else
                {
                    dp[i][j] = (s[i-1] == p[j-1] || p[j-1] == '.') && dp[i-1][j-1];
                }
            }
        }
        
        return dp[s.size()][p.size()];
    }
};

typedef SolutionDP Solution;


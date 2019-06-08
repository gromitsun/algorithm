/* Runtime: 20 ms, faster than 98.76% of C++ online submissions for Course Schedule II. */ 
class Solution {
    // adjacency list
    vector<vector<int>> adj;
    // node is being visited?
    vector<bool> visited;
    // node has been visited?
    vector<bool> finished;
    
    // result stack
    deque<int> s;
    
    // construct adj list
    inline void init(int numCourses, vector<vector<int>>& prerequisites)
    {
        adj = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<bool>(numCourses, false);
        finished = vector<bool>(numCourses, false);
        
        // construct adj list
        for (auto& x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
    }
    
    // dfs to check for cycles in graph
    // and push node to result stack
    bool dfs(int i)
    {
        if (visited[i])
        {
            return !finished[i];
        }
        
        visited[i] = true;
        for (int j : adj[i])
        {
            if (dfs(j))
            {
                return true;
            }
        }
        finished[i] = true;
        
        // push node to stack
        s.push_front(i);
        
        // no cycles found
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses, prerequisites);
        
        for (int i=0; i<numCourses; i++)
        {
            if (dfs(i))
            {
                return vector<int>();
            }
        }
        return vector<int>(s.begin(), s.end());
    }
};


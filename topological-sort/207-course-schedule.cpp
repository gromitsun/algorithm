/* Runtime: 16 ms, faster than 99.16% of C++ online submissions for Course Schedule. */
class Solution {
    // adjacency list
    vector<vector<int>> adj;
    // node is being visited?
    vector<bool> visited;
    // node has been visited?
    vector<bool> finished;
    
    // construct adj list
    inline void init(int numCourses, vector<vector<int>>& prerequisites)
    {
        adj = vector<vector<int>>(numCourses, vector<int>());
        visited = vector<bool>(numCourses, false);
        finished = vector<bool>(numCourses, false);
        
        for (auto& x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
    }
    
    // dfs to check for cycles in graph
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
        // no cycles found
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses, prerequisites);
        
        for (int i=0; i<numCourses; i++)
        {
            if (dfs(i))
            {
                return false;
            }
        }
        return true;
    }
};


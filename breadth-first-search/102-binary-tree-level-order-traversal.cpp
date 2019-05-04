/** 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ret;
        
        // check empty input
        if (!root)
        {
            return ret;
        }
        
        // queue to store nodes for traversal
        deque<TreeNode*> q;// push root to queue
        q.push_back(root);
        // count nodes on a level
        int n_current = 1;  // current level
        int n_next = 0;  // next level
        
        // level values
        vector<int> level;
        
        // breath first search
        while (!q.empty())
        {
            // get a candidate from queue
            TreeNode* node = q.front();
            q.pop_front();
            
            // put node val into ret
            level.push_back(node->val);
            n_current--;

            // put leaves into queue
            if (node->left)
            {
                q.push_back(node->left);
                n_next++;
            }
            if (node->right)
            {
                q.push_back(node->right);
                n_next++;
            }
            
            // next level?
            if (n_current == 0)
            {
                n_current = n_next;
                n_next = 0;
                ret.push_back(level);
                level.clear();
                level.reserve(n_current);
            }
        }
        
        return ret;
    }
};


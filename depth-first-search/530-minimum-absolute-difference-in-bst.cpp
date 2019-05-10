efinition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class SolutionIterative {
    
    int m = INT_MAX;
    
    // previous value in in-order traversal -- for calculating min diff
    int prev_val = -1;
    
    void inorder(TreeNode* root)
    {
        stack<TreeNode*> s;
        s.push(root);
        
        // previously visited node -- for DFS
        TreeNode* prev = root;

        // do DFS 
        while (!s.empty())
        {
            TreeNode* node = s.top();
            s.pop();
            
            if (node)
            {
                // first visit -- push children in stack
                if (prev)
                {
                    s.push(node->right);
                    s.push(node);
                    s.push(node->left);
                }
                // second visit -- get difference with previous
                else
                {
                    if (prev_val >= 0)
                    {
                        m = min(m, node->val - prev_val);
                    }
                    prev_val = node->val;
                }
            }
            
            prev = node;
        }
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        // get in-order traversal        
        // BST's in-order traversal is sorted
        inorder(root);
        
        return m;
    }
};


class SolutionRecursive {
    
    int m = INT_MAX;
    
    // previous value in in-order traversal -- for calculating min diff
    int prev_val = -1;
    
    void inorder(TreeNode* root)
    {
        if (root)
        {
            inorder(root->left);
            if (prev_val >= 0)
            {
                m = min(m, root->val-prev_val);
            }
            prev_val = root->val;
            inorder(root->right);
        }
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        // get in-order traversal        
        // BST's in-order traversal is sorted
        inorder(root);
        
        return m;
    }
};


typedef SolutionIterative Solution;
// typedef SolutionRecursive Solution;


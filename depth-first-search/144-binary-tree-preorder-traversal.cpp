/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* recursive solution */
class SolutionRecursive {
    vector<int> ret;
    
    void preorder(TreeNode* root)
    {
        if (root)
        {
            ret.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // recursive solution
        preorder(root);
        return ret;
    }
};


/* iterative solution */
class SolutionIterative {
    // return
    vector<int> ret;
    // stack for DFS
    deque<TreeNode*> s;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        // put root in stack
        s.push_back(root);
        
        // do dfs
        while (!s.empty())
        {
            // pop out a node
            TreeNode* node = s.back();
            s.pop_back();
            
            if (node)
            {
                 // put node value in ret
                ret.push_back(node->val);
                // first handle right
                s.push_back(node->right);
                // then handle left
                s.push_back(node->left);
            }
        }
        
        return ret;
    }
};

typedef SolutionIterative Solution;


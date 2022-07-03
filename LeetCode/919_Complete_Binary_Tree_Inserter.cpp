/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter 
{
struct th
{
    TreeNode* node;
    int lr;
};
public:
    TreeNode* root_;
    queue<th> qp;
    
    CBTInserter(TreeNode* root) : root_(root)
    {
        queue<TreeNode*> q;
        q.push(root_);
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left)
            {
                q.push(cur->left);
            }
            else
            {
                qp.push({cur, 0});
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
            else
            {
                qp.push({cur, 1});
            }
        }        
    }
    
    int insert(int val) 
    {
        if (!qp.empty())
        {
            th cur = qp.front();
            qp.pop();
            if (! cur.lr)
            {
                cur.node->left = new TreeNode(val);
                qp.push({cur.node->left, 0});
                qp.push({cur.node->left, 1});
            }
            else
            {
                cur.node->right = new TreeNode(val);
                qp.push({cur.node->right, 0});
                qp.push({cur.node->right, 1});
            }
            return cur.node->val;
        }
        return 0;
    }
    
    TreeNode* get_root() 
    {
        return root_;        
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
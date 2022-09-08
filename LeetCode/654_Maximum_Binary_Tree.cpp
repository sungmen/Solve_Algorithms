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
class Solution 
{
public:    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
	{
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }
        TreeNode* result = new TreeNode(pq.top().first);
        TreeNode* record = new TreeNode(pq.top().second);
        pq.pop();
        while (! pq.empty())
        {
            pair<int, int> cnt = pq.top();
            pq.pop();
            TreeNode* tresult = result, *trecord = record;
            while (nullptr != trecord)
            {
                if (trecord->val < cnt.second)
                {
                    if (! trecord->right)
                    {
                        tresult->right = new TreeNode(cnt.first);
                        trecord->right = new TreeNode(cnt.second);
                        break;
                    }
                    trecord = trecord->right;
                    tresult = tresult->right;
                }
                else
                {
                    if (! trecord->left)
                    {
                        tresult->left = new TreeNode(cnt.first);
                        trecord->left = new TreeNode(cnt.second);
                        break;
                    }
                    trecord = trecord->left;
                    tresult = tresult->left;
                }
            }
        }
        return result;
    }
};
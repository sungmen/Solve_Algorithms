/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "/x";
        string res = "/" + to_string(root->val);
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    TreeNode* deser(string data, int &idx)
    {
        idx += 1;
        string tmpStr = "";
        while (idx < data.size() && data[idx] != '/') 
        {
            tmpStr += data[idx];
            idx++;
        }
        if (tmpStr == "x")
            return nullptr;
        int tmpVal = stoi(tmpStr);
        TreeNode * res = new TreeNode(tmpVal);
        res->left = deser(data, idx);
        res->right = deser(data, idx);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deser(data, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
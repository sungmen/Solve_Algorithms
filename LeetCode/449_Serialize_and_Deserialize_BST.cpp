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
  string serialize(TreeNode *root) {
    string str = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *cur = q.front();
      q.pop();
      if (cur == nullptr) {
        str += "_-";
        continue;
      }
      str += (to_string(cur->val) + '-');
      q.push(cur->left);
      q.push(cur->right);
    }
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data == "_-")
      return nullptr;
    int idx = 0;
    string str = "";
    for (; idx < data.size(); idx++) {
      if (data[idx] == '-') {
        idx++;
        break;
      }
      str += data[idx];
    }
    int nNum = stoi(str);
    TreeNode *root = new TreeNode(nNum);
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    q.push({root, 1});
    while (!q.empty()) {
      TreeNode *cur = q.front().first;
      int lr = q.front().second;
      q.pop();
      if (data[idx] == '_') {
        idx += 2;
        continue;
      }
      string str = "";
      for (; idx < data.size(); idx++) {
        if (data[idx] == '-') {
          idx++;
          break;
        }
        str += data[idx];
      }
      int nNum = stoi(str);
      if (0 == lr) {
        cur->left = new TreeNode(nNum);
        cur = cur->left;
      } else {
        cur->right = new TreeNode(nNum);
        cur = cur->right;
      }
      q.push({cur, 0});
      q.push({cur, 1});
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

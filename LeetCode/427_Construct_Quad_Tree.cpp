/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
public:
  Node *construct(vector<vector<int>> &grid, int s = -1, int n = -1, int u = -1,
                  int m = -1) {
    n = n == -1 ? grid.size() : n;
    m = m == -1 ? grid[0].size() : m;
    s = s == -1 ? 0 : s;
    u = u == -1 ? 0 : u;
    int t = grid[s][u];
    bool chk = true;
    for (int i = s; i < n; i++) {
      for (int j = u; j < m; j++) {
        if (t != grid[i][j]) {
          chk = false;
          break;
        }
      }
      if (chk == false)
        break;
    }
    Node *node = new Node((chk == true ? t : 1), chk);
    if (chk == true) {
      return node;
    }
    node->topLeft = construct(grid, s, (s + n) / 2, u, (u + m) / 2);
    node->topRight = construct(grid, s, (s + n) / 2, (u + m) / 2, m);
    node->bottomLeft = construct(grid, (s + n) / 2, n, u, (u + m) / 2);
    node->bottomRight = construct(grid, (s + n) / 2, n, (u + m) / 2, m);
    return node;
  }
};

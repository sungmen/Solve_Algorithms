/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
  vector<NestedInteger> nestedList;
  vector<int> ans;
  int idx = 0;
  int size = 0;
  vector<int> dfs(vector<NestedInteger> &v) {
    vector<int> res;
    for (auto i : v) {
      if (i.isInteger()) {
        res.push_back(i.getInteger());
      } else {
        vector<int> tmp = dfs(i.getList());
        for (auto j : tmp)
          res.push_back(j);
      }
    }
    return res;
  }

  NestedIterator(vector<NestedInteger> &nestedList) { ans = dfs(nestedList); }

  int next() { return ans[idx++]; }

  bool hasNext() { return idx < ans.size(); }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

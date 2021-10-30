#include <bits/stdc++.h>
using namespace std;
long long  res = 0;
// class Node {
// public:
//     int val;
//     Node *left, *right;
//     Node() {
//         val = 0;
//         left = nullptr;
//         right = nullptr;
//     }
//     Node(int val) {
//         this->val = val;
//         left = nullptr;
//         right = nullptr;
//     }
// };
// void insert(Node * node, int x, int idx) {
//     if (node->val < x) {
//         if (node->left != nullptr) {
//             insert(node->left, x, idx + 1);
//         } else {
//             node->left = new Node(x);
//             res += idx + 1;
//         }
//     } else {
//         if (node->right != nullptr) {
//             insert(node->right, x, idx + 1);
//         } else {
//             node->right = new Node(x);
//             res += idx + 1;
//         }
//     }
// }
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<long long> v(n);
    set<int> s;
    for (int t = 0; t < n; ++t) {
        int p; cin >> p;
        long long l = 0, r = 0;
        auto iter = s.lower_bound(p);
        if (iter != s.end()) {
            r = v[*iter];
        }
        if (iter != s.begin()) {
            l = v[*(--iter)];
        }
        v[p] = 1 + max(l, r);
        s.insert(p);
        res += v[p];
    }
    // int p; cin >> p;
    // Node* start = new Node(p);
    // for (int i = 1; i < n; ++i) {
    //     cin >> p;
    //     Node* head = start;
    //     insert(head, p, 1);
    // }
    cout << res;
    return 0;
}
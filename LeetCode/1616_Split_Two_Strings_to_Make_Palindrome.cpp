class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int l = 0, r = a.size() - 1;
        while (l < r && a[l] == b[r]) {
            l++, r--;
        }
        if (l >= r) return true;
        int l2 = l, r2 = r;
        while (l2 < r2 && a[l2] == a[r2]) {
            l2++, r2--;
        }
        if (l2 >= r2) return true;
        l2 = l, r2 = r;
        while (l2 < r2 && b[l2] == b[r2]) {
            l2++, r2--;
        }
        if (l2 >= r2) return true;
        l = 0, r = a.size() - 1;
        while (l < r && b[l] == a[r]) {
            l++, r--;
        }
        if (l >= r) return true;
        l2 = l, r2 = r;
        while (l2 < r2 && a[l2] == a[r2]) {
            l2++, r2--;
        }
        if (l2 >= r2) return true;
        l2 = l, r2 = r;
        while (l2 < r2 && b[l2] == b[r2]) {
            l2++, r2--;
        }
        if (l2 >= r2) return true;
        return false;
    }
}; 
/**
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Binary.
* Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Add Binary.
*/
class Solution {
public:
    string addBinary(string a, string b) {
        for (int i = 0; i < a.size() / 2; i++) {
            char tmp = a[i];
            a[i] = a[a.size() - 1 - i];
            a[a.size() - 1 - i] = tmp;
        }
        for (int i = 0; i < b.size() / 2; i++) {
            char tmp = b[i];
            b[i] = b[b.size() - 1 - i];
            b[b.size() - 1 - i] = tmp;
        }
        if (a.size() < b.size()) {
            int upper = 0;
            for (int i = 0; i < a.size(); i++) {
                int chr = a[i] - '0' + b[i] - '0' + upper;
                upper = chr / 2;
                b[i] = chr % 2 + '0';
            }
            for (int i = a.size(); i < b.size(); i++) {
                int chr = b[i] - '0' + upper;
                upper = chr / 2;
                b[i] = chr % 2 + '0';
            }
            if (upper) b += '1';
            for (int i = 0; i < b.size() / 2; i++) {
                char tmp = b[i];
                b[i] = b[b.size() - 1 - i];
                b[b.size() - 1 - i] = tmp;
            }
            return b;
        } else if (a.size() > b.size()) {
            int upper = 0;
            for (int i = 0; i < b.size(); i++) {
                int chr = a[i] - '0' + b[i] - '0' + upper;
                upper = chr / 2;
                a[i] = chr % 2 + '0';
            }
            for (int i = b.size(); i < a.size(); i++) {
                int chr = a[i] - '0' + upper;
                upper = chr / 2;
                a[i] = chr % 2 + '0';
            }
            if (upper) a += '1';
            for (int i = 0; i < a.size() / 2; i++) {
                char tmp = a[i];
                a[i] = a[a.size() - 1 - i];
                a[a.size() - 1 - i] = tmp;
            }
            return a;            
        } else {
            int upper = 0;
            for (int i = 0; i < b.size(); i++) {
                int chr = a[i] - '0' + b[i] - '0' + upper;
                upper = chr / 2;
                a[i] = chr % 2 + '0';
            }
            if (upper) a += '1';
            for (int i = 0; i < a.size() / 2; i++) {
                char tmp = a[i];
                a[i] = a[a.size() - 1 - i];
                a[a.size() - 1 - i] = tmp;
            }
            return a;
        }
    }
};
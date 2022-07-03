class Solution {
public:
    vector<int> strsplit(string str) {
        vector<int> vs;
        stringstream ss(str);
        string s;
        while (getline(ss, s, '.')) {
            vs.push_back(stoi(s));
        }
        return vs;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = strsplit(version1), v2 = strsplit(version2);
        if (v1.size() < v2.size()) {
            for (int i = v1.size(); i < v2.size(); i++) {
                v1.push_back(0);
            }
        } else if (v1.size() > v2.size()) {
            for (int i = v2.size(); i < v1.size(); i++) {
                v2.push_back(0);
            }
        }
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] < v2[i]) return -1;
            else if (v1[i] > v2[i]) return 1;
        }
        return 0;
    }
};
bool comp(string a, string b) {
    return a.size() > b.size();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        string str = (words[0] + "#");
        vector<int> shap;
        shap.push_back(str.size()-1);
        for (int i = 1; i < words.size(); i++) {
            bool chk = false;
            for (int j = 0; j < shap.size(); j++) {
                if (!str.compare(shap[j]-words[i].size(), words[i].size(), words[i])) {
                    chk = true;
                }
            }
            if (!chk) {
                str += (words[i]+"#");
                shap.push_back(str.size()-1);
            }
        }
        return str.size();
    }
};
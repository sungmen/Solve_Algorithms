class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        string str = "", star = "";
        vector<int> v, t;
        for (int i = 0; i < n; i++)
        {
            if (start[i] != '_')
            {
                str += start[i];
                v.push_back(i);
            }
            if (target[i] != '_')
            {
                star += target[i];
                t.push_back(i);
            }
        }
        
        if (str != star) return false;
        
        for (int i = 0; i < v.size(); i++)    
        {
            if (str[i] == 'L')
            {
                if (v[i] < t[i])
                {
                    return false;
                }
            }
            else
            {
                if (v[i] > t[i])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};
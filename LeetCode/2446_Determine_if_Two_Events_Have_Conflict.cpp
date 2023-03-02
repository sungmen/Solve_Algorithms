class Solution 
{
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) 
    {
        vector<int> str;
        for (int i = 0; i < 2; i++)
        {
            str.push_back(stoi(event1[i].substr(0, 2) + event1[i].substr(3, 2)));
            str.push_back(stoi(event2[i].substr(0, 2) + event2[i].substr(3, 2)));
        }
        return (str[0] <= str[3] && str[1] <= str[2]);
    }
};
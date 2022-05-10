class TopVotedCandidate 
{
public:
    map<int, int> m;
    int arr[5001];
    TopVotedCandidate(vector<int>& persons, vector<int>& times) 
    {
        memset(arr, -1, sizeof(arr));
        int tmp = persons[0], p = persons.size();
        for (int i = 0; i < p; i++)
        {
            if((++arr[persons[i]]) >= arr[tmp])
            {
                tmp = persons[i];
            }
            m[times[i]] = tmp;
        }
                
    }
    
    int q(int t) 
    {
        auto it = m.lower_bound(t);
        if (it->first != t)
        {
            return (--it)->second;
        }
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
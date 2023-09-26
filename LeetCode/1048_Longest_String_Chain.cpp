class Solution 
{
public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> unWords;
        for (auto word : words)
        {
            unWords[-word.size()].push_back(word);
        }
        int answer = 1;
        unordered_map<string, int> umCnt;
        for (auto it = unWords.begin(); it != unWords.end(); it++)
        {
            if (unWords.find(it->first-1) == unWords.end()) continue;
            for (auto i : it->second)
            {
                for (auto j : unWords[it->first-1])
                {
                    int p = 0;
                    int diff = 0;
                    for (int k = 0; k < j.size(); k++)
                    {
                        if (i[p] != j[k])
                        {
                            diff++;
                            if (diff > 1) break;
                        } else p++;
                    }
                    if (diff == 1)
                    {
                        umCnt[i] = max(umCnt[i], umCnt[j] + 1);
                        answer = max(answer, umCnt[i] + 1);
                    }
                }
            }
        }
        return answer;
    }
};
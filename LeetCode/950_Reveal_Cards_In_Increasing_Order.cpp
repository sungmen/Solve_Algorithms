class Solution 
{
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        queue<int> q;
        for (int i = 0; i < deck.size(); i++) q.push(i);
        for (int i = 0; i < deck.size(); i++)
        {
            res[q.front()] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};
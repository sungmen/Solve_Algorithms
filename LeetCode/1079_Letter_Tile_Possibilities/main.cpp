class Solution {
public:
    int numTilePossibilities(string tiles) {
        set<string> s;
        sort(tiles.begin(), tiles.end());
        s.insert("");
        for (auto str : tiles) {
            int t = s.size();
            set<string> tmp = s;
            for (set<string>::iterator it = tmp.begin(); it != tmp.end(); it++) {
                s.insert(*it + str);
            }
        }
        set<string> tmp = s;        
        for (set<string>::iterator it = tmp.begin(); it != tmp.end(); it++) {
            string str = *it;
            do {
                s.insert(str);
            } while(next_permutation(str.begin(), str.end()));
            
        }
        return s.size() - 1;
    }
};
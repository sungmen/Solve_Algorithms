class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m;
        for (auto c : text) {
            if (!m[c]) m[c] = 1;
            else {
                m[c]++;
            }
        }
        if (m.find('l')==m.end() || m.find('b')==m.end() || m.find('a')==m.end() || m.find('o')==m.end() || m.find('n')==m.end()) return 0;
        else {
            return min(m['l'], min(m['b'], min(m['l']/2, min(m['a'], m['o']/2))));
        }
        return 0;
    }
};
class CombinationIterator {
public:
    vector<bool> chk;
    vector<bool> init;
    string chr;
    int chknum = 0;
    CombinationIterator(string characters, int combinationLength) {
        chr = characters;
        for (int i = 0; i < combinationLength; i++) {
            chk.push_back(false);
            init.push_back(false);
        }
        for (int i = 0; i < characters.size() - combinationLength; i++) {
            chk.push_back(true);
            init.push_back(true);
        }
    }
    
    string next() {
        chknum++;
        string nextstr = "";
        for (int i = 0; i < chk.size(); i++) {
            if (!chk[i]) nextstr += chr[i];
        }
        next_permutation(chk.begin(), chk.end());
        return nextstr;
    }
    
    bool hasNext() {
        if (!chknum) return true;
        return (init == chk ? 0 : 1);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
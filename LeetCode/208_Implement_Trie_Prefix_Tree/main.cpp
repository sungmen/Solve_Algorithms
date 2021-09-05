class Trie {
private:
    map<string, int> swi, sch;
    
public:
    /** Initialize your data structure here. */
    Trie() {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        sch[word] = 1;
        string str = "";
        str += word[0];
        swi[str] = 1;
        for (int i = 1; i < word.size(); ++i) {
            str += word[i];
            swi[str] = 1;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (sch[word]) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (swi[prefix]) return true;
        return false;
    }
};
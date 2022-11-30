class RandomizedSet {
private:
    unordered_map<int, int> um;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (um.find(val) != um.end()) {
            return false;
        }
        um[val] = 1;
        return true;
    }
    
    bool remove(int val) {
        if (um.find(val) == um.end()) {
            return false;
        }
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        auto r_it = um.begin();
        advance(r_it, rand() % um.size());
        return r_it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
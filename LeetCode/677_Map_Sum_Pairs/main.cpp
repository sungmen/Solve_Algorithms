class MapSum {
private:
    map<string, int> m;
    map<string, int> check;
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        string str = "";
        if (check.find(key) == check.end()) {
            for (auto s : key) {
                str += s;
                m[str] += val;
            }
            check[key] = val;
        } else {
            int tmp = check[key];
            for (auto s : key) {
                str += s;
                m[str] -= tmp;
                m[str] += val;
            }
            check[key] = val;
        }
    }
    
    int sum(string prefix) {
        if (m.find(prefix) == m.end()) return 0;
        else return m[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
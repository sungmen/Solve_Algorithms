class TimeMap {
public:
    unordered_map<string, map<int, string>> msv;
    
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        msv[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        map<int, string>::iterator it = msv[key].upper_bound(timestamp);
        if (it == msv[key].begin())
        {
            return "";
        }
        else
        {
            it--;
            return it->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
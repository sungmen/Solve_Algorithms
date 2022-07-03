class Bitset {
public:
    int cnt = 0;
    int m = 0;
    string str, rev;
    // Init
    Bitset(int size) {
        m = size;
        str = string(m, '0');
        rev = string(m, '1');
    }
    
    // 0 -> 1
    void fix(int idx) {
        if (str[idx] == '0') {
            str[idx] = '1';
            rev[idx] = '0';
            cnt++;
        }
    }
    
    // 1 -> 0
    void unfix(int idx) {
        if (str[idx] != '0') {
            str[idx] = '0';
            rev[idx] = '1';
            cnt--;
        }
    }
    
    // reverse
    void flip() {
        swap(str, rev);
        cnt = m - cnt;
    }
    
    // check all is 1
    bool all() {
        return (cnt==m?1:0);
    }
    
    // least 1 index with value 1
    bool one() {
        return cnt;
    }
    
    // count 1
    int count() {
        return cnt;
    }
    
    // return string
    string toString() {
        return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
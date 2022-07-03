class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> res(n);
        for (int i = 0; i < 16; i++) {
            bool t = res[i];
            res[i] = res[32-i-1];
            res[32-i-1] = t;
        }
        return res.to_ulong();
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
        }
        if (curGas < 0) return -1;
        curGas = 0;
        int res = 0;
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            if (curGas < 0) {
                curGas = 0;
                res = i + 1;
            }
        }
        return res;
    }
};
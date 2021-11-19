class Solution {
public:
    queue<int> binary(int n) {
        queue<int> v;
        while (n) {
            v.push(n%2);
            n /= 2;
        }
        return v;
    }
    
    int hammingDistance(int x, int y) {
        queue<int> v1 = binary(x), v2 = binary(y);
        int answer = 0;
        while(!v1.empty() || !v2.empty()) {
            int idx = 0, idx2 = 0;
            if (!v1.empty()) {
                idx = v1.front();
                v1.pop();
            }
            if (!v2.empty()) {
                idx2 = v2.front();
                v2.pop();
            }
            if (idx != idx2) answer++;
        }
        return answer;
    }
};
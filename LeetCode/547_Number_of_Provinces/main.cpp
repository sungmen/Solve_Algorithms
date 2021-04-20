class Solution {
private:
    int arr[201];
    int allN;
    
public:
    void union_set() {
        for (int i = 0; i < 201; i++) arr[i] = i;
    }
    
    int find_union(int a) {
        if (arr[a] == a) return a;
        else return arr[a] = find_union(arr[a]);
    }
    
    void merge_union(int a, int b) {
        int fnd_a = find_union(a);
        int fnd_b = find_union(b);
        if (fnd_a == fnd_b) return;
        else {
            this->allN--;
            arr[fnd_a] = fnd_b;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        union_set();
        int sizeConnected = isConnected.size();
        this->allN = sizeConnected;
        for (int i = 0; i < sizeConnected-1; i++) {
            for (int j = i + 1; j < sizeConnected; j++) {
                if (isConnected[i][j]) {
                    merge_union(i, j);
                }
            }
        }
        return this->allN;
    }
};
/**
* Runtime: 80 ms, faster than 100.00% of C++ online submissions for Boats to Save People.
* Memory Usage: 41.9 MB, less than 100.00% of C++ online submissions for Boats to Save People.
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int cnt = 0, i = 0, j = people.size() - 1;
        while(i <= j) {
            if (people[j] > limit) {
                j--;
                if (i >= j) {
                    break;
                }
            } else if (people[j] == limit) {
                j--;
                cnt++;
                if (i > j) {
                    break;
                }
            } else {
                if (i == j) {
                    cnt ++;
                    break;
                }
                if (limit - people[j] >= people[i]) {
                    i++;
                }
                cnt++;
                if(i >= j) {
                    break;
                }
                j--;
            }
        }
        return cnt;
    }
};
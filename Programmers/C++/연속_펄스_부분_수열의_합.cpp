#include <vector>
using namespace std;

long long solution(vector<int> sequence) {
    int a = -1;
    long long backup1 = 0;
    long long cur1 = sequence[0];
    long long maxr1 = max(backup1, cur1);
    backup1 = max(backup1, -cur1);
    long long backup2 = 0;
    long long cur2 = -sequence[0];
    long long maxr2 = max(backup2, cur2);
    backup2 = max(backup2, -cur2);
    for (int i = 1; i < sequence.size(); i++)
    {
        cur1 = a * sequence[i] + cur1;
        maxr1 = max(maxr1, backup1 + cur1);
        backup1 = max(backup1, -cur1);
        cur2 = (-1 * a * sequence[i]) + cur2;
        maxr2 = max(maxr2, backup2 + cur2);
        backup2 = max(backup2, -cur2);
        if (a == 1) a = -1;
        else a = 1;
    }
    return max(maxr1, maxr2);
}
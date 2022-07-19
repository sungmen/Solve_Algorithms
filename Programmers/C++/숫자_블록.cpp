#include <math.h>
#include <vector>

using namespace std;
vector<int> solution(long long begin, long long end) 
{
    constexpr int MAX = 10000000;
    vector<int> answer;
    for (long long i = begin; i <= end; i++)
    {
        if (1 == i) 
        {
            answer.push_back(0);
            continue;
        }
        bool chk = 0;
        int r = sqrt(i);
        for (int j = 2; j <= r; j++)
        {
            if (i / j == (double)i / j && i / j <= MAX)
            {
                answer.push_back(i / j);
                chk = 1;
                break;
            }
        }
        if (!chk)
        {
            answer.push_back(1);
        }
    }
    return answer;
}
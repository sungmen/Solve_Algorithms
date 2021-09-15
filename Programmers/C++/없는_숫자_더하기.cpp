#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int i = 0, cnt = 0;
    while (i < 10) {
        if (i != numbers[cnt]) {
            answer += i;
            i++;
        } else {
            cnt ++;
            i++;
        }
    }
    return answer;
}
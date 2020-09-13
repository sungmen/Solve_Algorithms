#include <map>
#include <vector>
using namespace std;
int solution(vector<vector<string>> clothes) {
    map<string, int> cnt;
    for(auto i : clothes) cnt[i[1]]++;  // 각 종류별 저장
    int answer = 1;
    for(auto i : cnt) answer *= i.second + 1;   // 종류별로 경우의 수 안입는 경우 포함 +1
    return answer - 1;  // 모두 안입는 경우 제거를 위하여 -1
}

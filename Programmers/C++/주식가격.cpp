#include <vector>
std::vector<int> solution(std::vector<int> prices) {
    std::vector<int> answer(prices.size(), 0);
    for(int i = 0; i < prices.size(); i++)
        for(int j = i + 1; j < prices.size(); j++)
            if(prices[j] >= prices[i]) answer[i]++;
            else {
                answer[i]++;
                break;
            }
    return answer;
}

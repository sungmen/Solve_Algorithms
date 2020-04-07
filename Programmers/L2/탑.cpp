#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int size = heights.size();
    vector<int> answer(size, 0);
    for(int i = 1; i < size; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(heights[j] > heights[i]){
                answer[i] = j+1;
                break;
            }
        }
    }
    return answer;
}

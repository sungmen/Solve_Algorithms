#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int count = 0, max = 0;
    for(int i = 0; i < progresses.size(); i++) {
        int asu = (100-progresses[i])/speeds[i];
        if(((100-progresses[i])%speeds[i]))
            ++asu;
        
        if(i == 0) {
            max = asu;
            count++;
        } else if(i == progresses.size()-1) {
            if(max < asu) {
                answer.emplace_back(count);
                count = 1;
            } else{
                count++;
            }
            answer.emplace_back(count);
        } else {
            if(max < asu) {
                answer.emplace_back(count);
                max = asu;
                count = 1;
            } else {
                count++;
            }
        }
        
    }
    
    return answer;
}

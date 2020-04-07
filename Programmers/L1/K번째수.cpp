#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    int Size = commands.size();
    vector<int> answer(Size);
    
    for(int test_case = 0; test_case < Size; test_case++) {
        vector<int> case_v;
        
        for(int Case = commands[test_case][0]-1; Case <= commands[test_case][1]-1; Case++)
            case_v.emplace_back(array[Case]);
        
        sort(case_v.begin(), case_v.end());
        
        answer[test_case] = case_v[commands[test_case][2]-1];
    }
    
    return answer;
}
class Solution {
public:
  int minNumberOfHours(int initialEnergy, int initialExperience,
                       vector<int> &energy, vector<int> &experience) {
    int n = energy.size();
    int answer = 0;
    int sub = initialEnergy;
    int sum = initialExperience;
    int diffEnergy = 0;
    int diffExperience = 0;
    for (int i = 0; i < n; i++) {
      if (sum <= experience[i]) {
        diffExperience = experience[i] - sum;
        answer += diffExperience + 1;
        sum += diffExperience + 1;
      }

      if (sub <= energy[i]) {
        diffEnergy = energy[i] - sub;
        answer += diffEnergy + 1;
        sub += diffEnergy + 1;
      }

      sub -= energy[i];
      sum += experience[i];
    }

    return answer;
  }
};

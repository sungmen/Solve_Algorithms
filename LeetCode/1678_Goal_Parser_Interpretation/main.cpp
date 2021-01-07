class Solution {
public:
    string interpret(string command) {
        int i = 0;
        string ans = "";
        while(i < command.size()) {
            if (command[i] == 'G') {
                ans += 'G';
                i++;
                continue;
            } else if (command[i] == '(') {
                i++;
                if(command[i]==')') {
                    ans += 'o';
                    i++;
                    continue;
                } else {
                    ans += "al";
                    i += 3;
                    continue;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        string str = "";
        for (auto i : path) {
            if (i == '/' && str != "") {
                if (str == "..") {
                    if (!dq.empty()) {
                        dq.pop_back();
                    }
                } else if(str != ".") {
                    dq.push_back(str);
                }
                str = "";
            } else if (i != '/') {
                str += i;
            }
        }
        if (str == "..") {
            if (!dq.empty()) {
                dq.pop_back();
            }
        } else if(str != "" && str != ".") {
            dq.push_back(str);
        }
        string res = "";
        while (!dq.empty()) {
            res += '/';
            res += dq.front();
            dq.pop_front();
        }
        if (res.size() == 0) return "/";
        else return res;   
    }
};
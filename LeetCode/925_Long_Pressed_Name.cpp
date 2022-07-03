class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nameSize = name.size(), typedSize = typed.size();
        if (nameSize > typedSize) return false;
        int l = 0, r = 0;
        while (l < nameSize && r < typedSize) {
            char tmp = name[l];
            while (l < nameSize && r < typedSize && tmp == name[l] && name[l] == typed[r]) {
                l++;
                r++;
            }
            if (l < nameSize && tmp == name[l]) return false;
            while (r < typedSize && tmp == typed[r]) {
                r++;
            }
        }
        if (l != nameSize || r != typedSize) return false;
        return true;
    }
};
class Solution 
{
public:
    string complexNumberMultiply(string num1, string num2) 
    {
        int l1 = 0, r1 = 0, l2 = 0, r2 = 0, i = 0;
        while (num1[i++] != '+');
        l1 = stoi(num1.substr(0,i - 1));
        r1 = stoi(num1.substr(i, num1.size() - i + 1));
        i = 0;
        while (num2[i++] != '+');
        l2 = stoi(num2.substr(0, i - 1));
        r2 = stoi(num2.substr(i, num2.size() - i + 1));
        return to_string((l1 * l2) - (r1 * r2)) + "+" + to_string((l1 * r2) + (l2 * r1)) + "i";    
    }
};

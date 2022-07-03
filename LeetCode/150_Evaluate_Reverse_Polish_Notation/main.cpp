class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int arr[10001];
        int idx = 0;
        int tmp1 = 0, tmp2 = 0;
        for (string tok : tokens) {
            switch(tok[0]) {
            case '+':
                tmp1 = arr[idx--];
                tmp2 = arr[idx];
                arr[idx] = tmp1+tmp2;
                break;
            case '-':
                if (tok.size() == 1) {
                    tmp1 = arr[idx--];
                    tmp2 = arr[idx];
                    arr[idx] = tmp2-tmp1;
                } else {
                    arr[++idx] = stoi(tok);                    
                }
                break;
            case '*':
                tmp1 = arr[idx--];
                tmp2 = arr[idx];
                arr[idx] = tmp1*tmp2;
                break;
            case '/':
                tmp1 = arr[idx--];
                tmp2 = arr[idx];
                arr[idx] = tmp2/tmp1;
                break;
            default:
                arr[++idx] = stoi(tok);
                break;
            }
        }
        return arr[1];
    }
};
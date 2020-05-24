#include <iostream>
using namespace std;

int compare (string A, string B) {
    int count = 0;
    for (int i = 0; i < B.length(); i++)
            if (A[i] != B[i])
                count++;
    return count;
}

int compare_d(string A, string B) {
    int count = 0;
    int Min = 50;
    for (int i = A.length()-1; i < B.length(); i++) {
        count = 0;
        for (int j = 0; j < A.length(); j++) {
            if(A[j] != B[i-A.length()+1+j]){
                count++;
            }
        }
        Min = min(Min, count);
    }
    return Min;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    string A, B;
    cin >> A;
    cin.clear();
    cin >> B;

    if (A.length() != B.length()){
        cout << compare_d(A, B);
        return 0;
    }
    else {
        cout << compare(A, B);
        return 0;
    }
    return 0;
}
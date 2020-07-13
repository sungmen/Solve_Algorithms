#include<iostream>
 
using namespace std;
 
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        int f = n / 100, s = n % 100;
         
        if (f <= 12 && f >= 1 && s <= 12 && s >= 1)
        {
            cout << "#" << test_case << " AMBIGUOUS" << "\n";
            continue;
        }
       if ((f > 12 || f == 0) && (s <= 12 && s >= 1))
        {
            cout << "#" << test_case << " YYMM" << "\n";
            continue;
        }
        if ((f <= 12 && f >= 1) && (s > 12|| s== 0 ))
        {
            cout << "#" << test_case << " MMYY" << "\n";
            continue;
        } 
       cout << "#" << test_case << " NA" << "\n";
    }
    return 0;
}
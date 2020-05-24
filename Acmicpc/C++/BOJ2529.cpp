// BOJ2529.cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl    "\n"

void Check_Max(int k, char *inequality){
    vector<int> v;
    for(int i = 9; i >= 9-k; i--)
        v.push_back(i);
    
    bool t = false;
    do{
        for(int i = 0; i < k; i++) {
            switch(inequality[i]){
            case '<':
                if(v[i] < v[i+1])
                    t = true;
                else
                    t = false;
                break;
            case '>':
                if(v[i] > v[i+1])
                    t = true;
                else
                {
                    t = false;
                }
                break;
            }
            if(!t)
                break;
        }
    } while(!t && prev_permutation(v.begin(), v.end()));
    for (int i = 0; i <= k; i++)
        cout << v[i];
    cout << endl;
}

void Check_Min(int k, char *inequality) {
    vector<int> v;
    for(int i = 0; i <= k; i++)
        v.push_back(i);
    bool t = false;
    do{
        for(int i = 0; i < k; i++) {
            switch(inequality[i]){
            case '<':
                if(v[i] < v[i+1])
                    t = true;
                else
                    t = false;
                break;
            case '>':
                if(v[i] > v[i+1])
                    t = true;
                else
                {
                    t = false;
                }
                break;
            }
            if(!t)
                break;
        }
    } while(!t && next_permutation(v.begin(), v.end()));
    for (int i = 0; i <= k; i++)
        cout << v[i];
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int k;
    cin >> k;
    char *inequality = new char[k];
    for (int i = 0 ; i < k; i++)
        cin >> inequality[i];
    Check_Max(k, inequality);
    Check_Min(k, inequality);
    return 0;
}

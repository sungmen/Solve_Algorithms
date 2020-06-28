// BOJ10814

#include <iostream>
#include <vector>
#include <algorithm>
#define endl    '\n'
bool compare(std::pair<int, std::string> v1, std::pair<int, std::string> v2) 
{
    if(v1.first < v2.first)
        return true;
    else if (v1.first == v2.first)
        return false;
    return false;
}

int main () {
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int N;
    std::cin >> N;

    std::vector <std::pair<int, std::string> > v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i].first >> v[i].second;
    }

    stable_sort(v.begin(), v.end(), compare);
    

    for (int i = 0; i < N; i++)
        std::cout << v[i].first << " " << v[i].second << endl;

    return 0;
}

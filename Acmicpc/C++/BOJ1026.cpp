#include <iostream>
#include <vector>
#include <algorithm>

bool comp(int n1, int n2){
    return n1 > n2;
}

int main () {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), comp);

    int sum = 0;
    for (int  i =0 ;i < n; i++) {
        sum += a[i] * b[i];
    }

    printf("%d", sum);
    
    return 0;
}

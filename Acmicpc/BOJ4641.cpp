#include <cstdio>
#include <vector>
int main() {
    int n;
    int num = 0;
    std::vector<int> v;
    do{
        scanf("%d", &n);
        if (n == 0) {
            for(int i = 0; i < v.size(); i++) {
                for (int j = 0; j < v.size(); j++) {
                    if(v[i] / v[j] == 2 && !(v[i] % v[j])) {
                        num++;
                    }
                }
            }
            printf("%d\n", num);
            num = 0;
            v.clear();
        } else 
            v.emplace_back(n);
    }while(n != -1);

    return 0;
}
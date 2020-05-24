#include <iostream>
using namespace std;
long num[9]={9,90,900,9000,90000,900000,9000000,90000000,1};
int main() {
    string number;
    cin >> number;
    int length = number.size();
    long sum = 0;
    int mi = 0;
    for(int i = 0; i < length-1; i++) {
        sum += num[i] * (i+1);
        mi += num[i];
    }
    sum += (atoi(number.c_str()) - mi) * length;
        
    printf("%ld", sum);

    

    return 0;
}
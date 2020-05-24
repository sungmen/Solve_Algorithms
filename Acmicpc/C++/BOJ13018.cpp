// https://www.acmicpc.net/problem/13018

#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

void sequence(int n, int k) {
    int d = n - k;
    int* a = new int[n];
    for (int i = 1; i <= n; i++)
        a[i - 1] = i;

    if (n == k) {
        cout << "Impossible" << endl;
        delete a;
        return;
    }
    else if (d == 1) {
        for (int i = 0; i < n; i ++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        delete a;
        return;
    }
    else {
        int temp = 0;
        for (int i = 1; i < d; i++) {
            temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
        }
        int j = 0;
        while (true) {
            j = 0;
            for (int i = 1; i < d; i++) {
                if (gcd(i, a[i - 1]) != 1) {
                    for (int i = 1; i < d; i++) {
                        temp = a[i];
                        a[i] = a[i - 1];
                        a[i - 1] = temp;
                    }
                }
                else
                    j++;
            }
            if (j == d-1)
                break;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        delete a;
        return;
    }
}

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    sequence(n, k);

    return 0;
}

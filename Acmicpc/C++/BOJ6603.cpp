#include <iostream>
using namespace std;

int n;
int *arr;
int *sel;

void print();
void DFS(int idx, int cnt);

int main() {
    scanf("%d", &n);
    arr = new int[n];
    sel = new int[n];
    if(n==0)
        return 0;
    while(true) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        DFS(0, 0);
        cout << '\n';
        scanf("%d", &n);
        arr = new int[n];
        
        sel = new int[n];
        if (n == 0)
            return 0;
    }
}
void print() {
    for (int i = 0; i < n; i++)
        if (sel[i] == 1)
            cout << arr[i] << " ";
    cout << endl;
}
void DFS(int idx, int cnt) {
    if (cnt == 6) {
        print();
        return;
    }

    for (int i = idx; i < n; i++) {
        if(sel[i] == 1)
            continue;
        sel[i] = 1;

        DFS(i, cnt+1);
        sel[i] = 0;
    }
}

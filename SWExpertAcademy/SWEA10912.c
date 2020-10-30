#include <stdio.h>
#include <string.h>
int main() {
    // freopen("input.txt", "r", stdin);
    int t;scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++) {
        int n[27];
        char s[102];
        memset(n, 0, sizeof(n));
        memset(s, EOF, sizeof(s));
        scanf("%s", &s);
        int i = 0;
        while(s[i] != EOF) {
            n[s[i]-'a']++;
            i++;
        }
        char a[27];
        int j = 0;
        for(i = 0; i < 26; i++) {
            if(n[i]%2) {
                a[j++] = i + 'a';
            }
        }
        printf("#%d ", tc);
        if(j == 0) {
            printf("Good\n");
        } else {
            for(i = 0; i < j; i++) printf("%c", a[i]);
            printf("\n");
        }
    }
}
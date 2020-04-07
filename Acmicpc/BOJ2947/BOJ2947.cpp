#include <stdio.h>
#define swap(a,b,temp) {temp=a; a=b; b=temp;}

void bubble(int* n) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4-i; j++) {
            int t;
            if(n[j] >= n[j+1]) {
                swap(n[j],n[j+1],t);
                for(int l = 0; l < 5; l ++)
                    printf("%d ",n[l]);
                printf("\n");
            }
        }
    }
}

int main() {
    int n[5];
    for(int i = 0; i <5; i ++)
        scanf("%d", &n[i]);
    bubble(n);

    return 0;
}
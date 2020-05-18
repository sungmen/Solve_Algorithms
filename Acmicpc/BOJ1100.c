#include <stdio.h>
char chess[8];

int main() {
    int res = 0;
    for(int i = 0; i < 8; i++){
        scanf("%s", &chess);
        if(!(i%2)) {
            for(int j = 0; j < 8; j++){
                if(!(j % 2) && chess[j] == 'F'){
                    res++;
                }
            }
        }
        else {
            for(int j = 0; j < 8; j++){
                if(j%2 && chess[j] == 'F'){
                    res++;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}
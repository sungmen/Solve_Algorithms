#include <stdio.h>

int main() {
    while(1) {
        char chr[1000] = {' '};
        scanf("%s", &*chr);
        if(chr[0] == '0') break;
        int n = 0;
        for(int i = 0; i < sizeof(chr);i++){
            if(chr[i]==0) break;
            n+=chr[i]-'0';
        }
        while(n>9){
            int m = n;
            n = 0;
            for(;m!=0;m/=10)
                n+=m%10;
        }
        printf("%d\n", n);
    }

    return 0;
}
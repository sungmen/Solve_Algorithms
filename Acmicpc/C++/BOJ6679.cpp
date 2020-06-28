#include <stdio.h>
int main() {
    for(int i = 2992; i < 10000; i++) {
        int dec = 0, tw = 0, he = 0;
        int p = i;
        while(p)
            dec += p % 10, p /= 10; 
        p = i;
        while(p)
            tw += p % 12, p /= 12;
        if(dec == tw) {
            p = i;
            while(p)
                he += p % 16, p /= 16;
            if (dec == he)
                printf("%d\n", i);
        }
    }



    return 0;
}
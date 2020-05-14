#include <stdio.h>

char cro[101];

int main() {
    scanf("%s", cro);
    int cnt = 0, i = 0;
    while(cro[i]!='\0') {
        if(cro[i] == 'c') {
            if(cro[i+1] == '=' || cro[i+1] == '-')
                ++i;
        } else if(cro[i] == 'd') {
            if(cro[i+1] == 'z' && cro[i+2] == '=')
                i+=2;
            if(cro[i+1] == '-')
                ++i;
        } else if(cro[i] == 'l' && cro[i+1] == 'j') {
            ++i;
        } else if(cro[i] == 'n' && cro[i+1] == 'j') {
            ++i;
        } else if(cro[i] == 's' && cro[i+1] == '=') {
            ++i;
        } else if(cro[i] == 'z' && cro[i+1] == '=') {
            ++i;
        }
        cnt++;
        i++;
    }
    printf("%d", cnt);

    return 0;
}
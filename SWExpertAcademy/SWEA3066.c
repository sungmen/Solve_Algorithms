#include <stdio.h>
int main(){
    int TC;
    scanf("%d",&TC);
    for(int t= 1;t<=TC;t++){
        int N,M,K;
        scanf("%d %d %d",&N,&M,&K);
        printf("#%d %d\n",t,(N+M-K)/3>(N>>1)?(((N>>1)>M)?M:(N>>1)):(((N+M-K)/3>M)?M:(N+M-K)/3));
    }
}

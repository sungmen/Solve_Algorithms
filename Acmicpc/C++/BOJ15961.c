#include <stdio.h>

int nCnt[3000001];
int kCnt[3001];

int main() {
    /*
    *  n 접시의 수
    *  d 가짓수
    *  k 연속 접시의 수
    *  c 쿠폰 번호
    */
    int n, d, k, c;
    scanf("%d%d%d%d", &n, &d, &k, &c);

    int i;
    for(i = 0; i < n; i++){
        scanf("%d", &nCnt[i]);
    }

    int cnt = 0;    // 경우 수
    for(i = n - k; i < n; i++) {
        if(!kCnt[nCnt[i]])
            cnt++;
        kCnt[nCnt[i]]++;
    }

    int max_ = 0;   // 최대 수
    for(i = 0; i < n; i++) {
        if(!kCnt[nCnt[i]])
            cnt++;
        kCnt[nCnt[i]]++;
        d = i - k;
        if(d < 0)
            d += n;
        if(kCnt[nCnt[d]] == 1)
            cnt--;
        kCnt[nCnt[d]]--;
        max_ = max_ > cnt + (kCnt[c] == 0) ? max_ : cnt + (kCnt[c] == 0);
    }

    printf("%d", max_);

    return 0;
}
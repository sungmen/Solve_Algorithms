function solution(n,a,b)
{
    let cnt = 0;
    while(true) {
        if(a%2 == 1) {
            a+=1;
            a = a/2;
        } else {
            a = a/2;
        }
        if (b%2 == 1) {
            b += 1;
            b = b/2;
        } else {
            b = b/2;
        }
        cnt++;
        if(a == b) {
            return cnt;
        }
    }

    return answer;
}
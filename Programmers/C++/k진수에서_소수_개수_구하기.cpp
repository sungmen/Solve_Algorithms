using namespace std;
bool prim(long long num) {
    long long i = 2;
    if (num == 1) return false;
    while(i * i <= num) {
        if (!(num % i)) return false;
        i++;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    long long tmp = 0, cnt = 1;
    while (n) {
        if (!(n%k)) {
            if (tmp && prim(tmp)) {
                answer ++;
            }
            cnt = 1, tmp = 0;
        } else {
            tmp = (n % k) * cnt + tmp;
            cnt *= 10;
        }
        n /= k;
    }
    return (tmp && prim(tmp) ? answer + 1 : answer);
}
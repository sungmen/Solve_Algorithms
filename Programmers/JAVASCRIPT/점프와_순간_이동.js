const solution = (n) => {
    let answer = 0;
    while(n)
        if(!(n % 2)) n /= 2;
        else {
            --n;
            ++answer;
        }
    return answer;
}
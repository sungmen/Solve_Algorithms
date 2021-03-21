const solution = (n, t, m, p) => {
    let str = '', answer = '', k = 0;
    while(1) {
        str += (k++).toString(n);   
        if (str.length > m * t) break;
    }
    str = str.toUpperCase();
    let answer = '';
    --p;
    while(t--) {
        answer += str[p];
        p += m;
    }
    return answer;
}
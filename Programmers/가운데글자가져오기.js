function solution(s) {
    var answer = '';
    let size = s.length;
    
    if(size % 2 == 0) {
        answer += s[size / 2 - 1];
        answer += s[size / 2];
    } else
        answer += s[parseInt(size / 2) ];
    return answer;
}

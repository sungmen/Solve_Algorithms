function solution(numbers) {
    var answer = [];
    for (let i = 0; i < numbers.length; i++) {
        let t = numbers[i].toString(2);
        let chk = false;
        for (let j = t.length-1; j >= 0; j--) {
            if (t[j] == '0') {
                if (j != t.length-1) {
                    t = t.substring(0, j) + '10' + t.substring(j+2, t.length);
                } else {
                    t = t.substring(0, j) + '1' + t.substring(j+1, t.length);
                }
                chk = true;
                break;
            }
        }
        if (!chk) {
            t = '10' + t.substring(1, t.length);    
        }
        answer.push(parseInt(t, 2));
    }
    return answer;
}
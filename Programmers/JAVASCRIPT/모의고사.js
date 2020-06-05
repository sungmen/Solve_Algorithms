function solution(answers) {
    let n1 = [1, 2, 3, 4, 5];
    let n2 = [2, 1, 2, 3, 2, 4, 2, 5];
    let n3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    var answer = [];
    let cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(let i = 0; i < answers.length; i++) {
        let n1_n = i % 5;
        let n2_n = i % 8;
        let n3_n = i % 10;
        if (answers[i] == n1[n1_n])
            cnt1++;
        if (answers[i] == n2[n2_n])
            cnt2++;
        if (answers[i] == n3[n3_n])
            cnt3++;
    }
    if (cnt1 == cnt2 && cnt2 == cnt3)
        return [1, 2, 3];
    else if (cnt1 > cnt3 && cnt1 == cnt2)
        return [1, 2];
    else if (cnt1 > cnt2 && cnt1 == cnt3)
        return [1, 3];
    else if (cnt2 > cnt1 && cnt2 == cnt3)
        return [2, 3];
    else {
        let m = Math.max(cnt1, Math.max(cnt2, cnt3));
        if (m == cnt1)
            return [1];
        else if (m == cnt2)
            return [2];
        else if (m == cnt3)
            return [3]
    }
    return answer;
}

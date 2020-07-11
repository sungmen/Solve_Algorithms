const solution = (n) => {
    let answer = [];
    for (let i = 0; i < n; i++) {
        if (i == 0)
        {
            answer.push(0);  
        }
        else {
            answer.push(0);
            for (let j = answer.length-2; j >= 0; j--)
            {
                answer.push(answer[j]^1)
            }
        }
    }
    return answer;
}
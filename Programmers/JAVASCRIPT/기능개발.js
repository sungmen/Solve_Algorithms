function solution(progresses, speeds) {
    var answer = [];
    let cnt = 1;
    let before = 0;
    let temp = 0;
    before = parseInt((100 - progresses[0]) / speeds[0]);
    for(let i = 1; i < progresses.length; i++) {
        temp = parseInt((100 - progresses[i]) / speeds[i]);
        if(before >= temp) 
            cnt++;
        else {
            answer.push(cnt);
            before = temp;
            cnt = 1;
        }
    }
    answer.push(cnt);
    return answer;
}
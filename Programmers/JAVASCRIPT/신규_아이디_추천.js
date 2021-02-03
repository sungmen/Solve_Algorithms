function solution(new_id) {
    let answer = new_id.toLowerCase().replace(/[^0-9a-z-_.]/g,'').replace(/[.]+/g,'.').replace(/(^[.])|([.]$)/g,'');
    answer = (answer === "" ? "aaa" : (answer.length > 15) ? answer.substr(0,15).replace(/([.]$)/g,''):answer);
    if(answer.length==1)answer += (answer + answer);
    if(answer.length==2)answer += (answer[1]);
    return answer;
}
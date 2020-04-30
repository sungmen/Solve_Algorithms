const solution = (arr) => {
    var answer = Math.max(...arr);
    let sum = answer;
    while(true) {
        let cnt = 0;
        for(let i = 0; i < arr.length; i++){
            if (answer % arr[i]){
                answer += sum;
                break;
            } else ++cnt;
        }
        if (cnt == arr.length)
            return answer;
    }
    return answer;
}
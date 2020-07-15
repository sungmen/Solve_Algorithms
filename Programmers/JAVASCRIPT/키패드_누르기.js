const dis = (x1, y1, x2, y2) => {
    return Math.abs(x1-x2)+Math.abs(y1-y2);
}

const solution = (numbers, hand) => {
    var answer = '';
    let arr = new Array(10);
    for (let i = 0; i < 10; i++){
        arr[i] = new Array(2);
    }
    arr[0][0] = 3;
    arr[0][1] = 1;
    let cnt  = 1;
    for(let i = 0; i < 3; i++) {
        for (let j = 0; j < 3; j++){
            arr[cnt][0] = i;
            arr[cnt][1] = j;
            cnt++;
        }
    }
    let l_finger = [3, 0];
    let r_finger = [3, 2];

    for (let i = 0; i < numbers.length; i++) {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            l_finger[0] = arr[numbers[i]][0];
            l_finger[1] = arr[numbers[i]][1];
        }
        if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            r_finger[0] = arr[numbers[i]][0];
            r_finger[1] = arr[numbers[i]][1];
        }
        if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0) {
            let l_dis = dis(l_finger[0], l_finger[1], arr[numbers[i]][0], arr[numbers[i]][1]); 
            let r_dis = dis(r_finger[0], r_finger[1], arr[numbers[i]][0], arr[numbers[i]][1]);
            if (l_dis < r_dis) {
                answer += 'L'
                l_finger[0] = arr[numbers[i]][0];
                l_finger[1] = arr[numbers[i]][1];
            } 
            else if (l_dis > r_dis) {
                answer += 'R'
                r_finger[0] = arr[numbers[i]][0];
                r_finger[1] = arr[numbers[i]][1];
            } 
            else if (l_dis == r_dis && hand == "left") {
                answer += 'L'
                l_finger[0] = arr[numbers[i]][0];
                l_finger[1] = arr[numbers[i]][1];
            } 
            else if (l_dis == r_dis && hand == "right") {
                answer += 'R'
                r_finger[0] = arr[numbers[i]][0];
                r_finger[1] = arr[numbers[i]][1];
            }
        }
    }

    return answer;
}
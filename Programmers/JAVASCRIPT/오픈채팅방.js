let solution = (record) => {
    let arr = new Array(record.length);
    let map = new Map();
    for(let i = 0; i < record.length; i++) {
        arr[i] = new Array(3);
        let t = record[i].split(' ');
        for(let j = 0; j < 3; j++) {
            arr[i][j] = t[j]
        }
        if(arr[i][0] != 'Leave')
            map.set(arr[i][1], arr[i][2]);
    }
    
    let answer = []
    for(let i = 0; i < record.length; i++) {
        if(arr[i][0] === 'Enter') {
            answer.push(map.get(arr[i][1]) + "님이 들어왔습니다.");
        }
        if(arr[i][0] == 'Leave'){
            answer.push(map.get(arr[i][1]) + "님이 나갔습니다.");            
        }
    }
        
    return answer;
}
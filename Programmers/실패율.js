const solution=(N, stages)=>{
    let answer = [];
    let len = stages.length;
    stages.sort((a,b)=>a-b);
    
    for(let i = 0; i < N; i++) {
        let cnt = 0;
        let lent = len;
        for(let j = 0; j < stages.length; j++) {
            if(stages[j] == i+1) {
                cnt++;
                len--;
            } else if(stages[j] > i+1)
                break;
        }
        
        if(cnt)
            answer.push({"keys":i+1, "values":cnt/lent});
        else
            answer.push({"keys":i+1, "values":0});
    }
    return answer.sort((a,b)=>{
        if (a.values > b.values) return -1
        if (a.values < b.values) return 1
        return a.keys - b.keys
    }).map(e => e.keys)
}

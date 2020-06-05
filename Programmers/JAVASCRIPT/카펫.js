function solution(brown, yellow) {
    var answer = [];
    let brye=brown+yellow
    let factori = parseInt(Math.sqrt(brye));
    for(let i = 3; i <= factori; i++) {
        if(brye % i == 0) {
            let j = brye / i;
            let ini = i - 2;
            let inj = j - 2;
            if(yellow == ini * inj && brown == brye - yellow) {
                return [j, i];
            } 
        }
    }
    
    return answer;
}
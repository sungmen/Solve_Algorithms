let solution = (people, limit) => {
    let answer = 0;
    people.sort((a,b)=>{return a - b;})
    let s = 0, l = people.length-1;
    while (s <= l) {
        people[s] + people[l] <= limit ? s++ & l-- : l--;
        answer++;
    }
    return answer;
}
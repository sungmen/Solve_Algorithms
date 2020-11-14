function solution(genres, plays) {
    var answer = [];
    let gen = new Map();
    for (let i = 0; i < genres.length; i++) {
        if (!gen.has(genres[i])) gen.set(genres[i], plays[i]);
        else gen.set(genres[i], gen.get(genres[i]) + plays[i])
    }
    let gen_total_sort = new Map([...gen.entries()].sort((a, b) => b[1] - a[1]));
    
    for(let k of gen_total_sort.keys()) {
        let m = new Map();
        for (let i = 0; i < genres.length; i++) {
            if(k == genres[i]) {
                m.set(i, plays[i]);
            }
        }
        let m_sort = new Map([...m.entries()].sort((a, b) => b[1] - a[1]));
        let i = 0;
        for (let a of m_sort.keys()) {
            answer.push(a)
            i++;
            if (i > 1) break;
        }
    }
    return answer;
}
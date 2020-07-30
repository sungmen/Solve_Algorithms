const solution = (n, words) => {
    let before = words[0];
    let map = new Map();
    map.set(words[0], 0);
    for (let i = 1; i < words.length; i++) {
        let temp = words[i];
        if(before[before.length-1] != temp[0]) {
            return [parseInt(i%n)+1, parseInt(i/n)+1];
        }
        if (map.has(temp)) {
            return [parseInt(i%n)+1, parseInt(i/n)+1];
        } else {
            map.set(temp,i);
            before = temp;
        }        
    }
    return [0,0];
}
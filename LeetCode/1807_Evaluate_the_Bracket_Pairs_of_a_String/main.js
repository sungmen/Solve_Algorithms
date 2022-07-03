/**
 * @param {string} s
 * @param {string[][]} knowledge
 * @return {string}
 */
 var evaluate = function(s, knowledge) {
    let m = new Map();
    knowledge.map((i) => m.set('('+i[0]+')', i[1]));
    let bracketL = [...s.matchAll(/\(/g)].map(i=>i.index);
    let bracketR = [...s.matchAll(/\)/g)].map(i=>i.index);
    let res = s;
    for (let i = 0; i < bracketL.length; i++) {
        const tmpS = s.substring(bracketL[i], bracketR[i]+1);
        if (!m.has(tmpS)) {
            res = res.split(tmpS).join('?');
        } else {
            res = res.split(tmpS).join(m.get(tmpS));
        }
    }
    return res;
};
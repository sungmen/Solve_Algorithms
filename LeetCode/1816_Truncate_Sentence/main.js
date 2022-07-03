/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var truncateSentence = function(s, k) {
    const p = s.split(' ');
    let res = "";
    res += p[0];
    for (let i = 1; i < k; i++) res += (' ' + p[i]);
    return res;
};
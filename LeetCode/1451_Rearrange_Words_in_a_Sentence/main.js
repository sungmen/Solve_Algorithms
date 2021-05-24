/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function(text) {
    let v = text.toLowerCase().split(' ').sort((a, b)=>a.length - b.length);
    let res = "";
    res += v[0];
    for (let i = 1; i < v.length; i++) res += (" " + v[i]);
    return res.replace(/\b[a-z]/, l=>l.toUpperCase());
};
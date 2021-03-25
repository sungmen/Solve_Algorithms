const solution = (s) => {
    var ans = [];
    s = s.replace("{{", '').replace("}}",'').split("},{").sort((a,b)=> a.length - b.length);
    for (let i = 0; i < s.length; i++) {
        s[i] = s[i].split(",");
        for (let j = 0; j < s[i].length; j++) {
            s[i][j] = parseInt(s[i][j]);
            ans.includes(s[i][j])?ans:ans.push(s[i][j]);
        }
    }
    return ans;
}
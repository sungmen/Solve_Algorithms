let solution = (s) => {
    return s.toLowerCase().replace(/\b[a-z]/g,function(f){return f.toUpperCase();});
}
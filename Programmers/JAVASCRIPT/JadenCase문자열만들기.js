let solution = (s) => {
    return s.toLowerCase().replace(/\b[a-z]/g,(f) => {return f.toUpperCase();});
}
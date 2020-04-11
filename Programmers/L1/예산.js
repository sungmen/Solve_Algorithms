const solution = (d, budget) => {
    d.sort((a,b)=>a-b);
    if(d[0] > budget) {
        return 0;
    } else {
        for (let i = 0; i < d.length; i++) {
            budget = budget - d[i];
            if (budget < 0) {
                return i;
            }
        }
        return d.length;
    }
}
const solution = (n) => {
    let len = n.toString(2).split('').filter(v=>v=='1').length

    while(1) {
        n++;
        if(n.toString(2).split('').filter(v=>v=='1').length == len){
            return n;
        }
    }
    return 0;
}
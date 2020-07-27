const solution = (s) => {
    var answer = true;
    let stk = [];
    
    for (let test_c = 0; test_c < s.length; test_c++) {
        if(s[test_c] == '(') {
            stk.push('(');
        }
        if(s[test_c] == ')'){
            if(stk.length != 0 && stk[stk.length - 1] == '(') {
                stk.pop();
            } else {
                return !answer;
            }
        } 
    }    
    if(stk.length != 0) {
        return !answer;
    } else {
        return answer;
    }
}
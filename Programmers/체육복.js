function solution(n, lost, reserve) {
    var answer = 0;
    let ans = [];
    for (let i = 0; i < n; i++)
        ans.push(1);
    
    for (let i = 0; i < lost.length; i++)
        ans[lost[i] - 1]--;
    for (let i = 0; i < reserve.length; i++)
        ans[reserve[i] - 1]++;
    
    if (ans[0] == 0) {
        if (ans[1]  == 2){
             ans[0]++;
             ans[1]--;
        }            
    }
    
    for (let i = 1; i < ans.length - 1; i++) {
        if (ans[i] == 0) {
            if (ans[i - 1]  == 2){
                ans[i]++;
                ans[i-1]--;
            }            
        }
        
        if (ans[i] == 0) {
            if (ans[i + 1]  == 2){
                ans[i]++;
                ans[i + 1]--;
            }            
        }
    }
    
    if (ans[n-1] == 0) {
        if (ans[n-2]  == 2){
             ans[n-1]++;
             ans[n-2]--;
        }            
    }
    
    for (let i = 0; i < n; i++)
        if (ans[i] >= 1) {
            answer++;
        }
    
    return answer;
}
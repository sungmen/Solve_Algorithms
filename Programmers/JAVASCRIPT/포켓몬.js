let solution = (nums) => {
    let len = nums.length / 2;
    let answer = nums.reduce((v, i) => v.includes(i) ? v : [...v, i], []).length;
    return len <= answer ? len : answer;
}
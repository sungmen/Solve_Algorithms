let row = new Array(11);
let col = new Array(11);
let x = 5, y = 5;
const left = () => {
    if(y-1 < 0) return;
    y--;
    col[x][y] = true;
}
const right = () => {
    if(y+1 > 10) return;
    col[x][y] = true;
    y++;
}
const up = () => {
    if (x+1 > 10) return;
    row[x][y] = true;
    x++;
}
const down = () => {
    if(x-1 < 0) return;
    x--;
    row[x][y] = true;
}
const solution = (dirs) => {
    let answer = 0;
    for (let i = 0; i < 11; i++) row[i] = new Array(11);
    for (let i = 0; i < 11; i++) col[i] = new Array(11);
    for (let i = 0; i < 11; i ++) for (let j = 0; j < 11; j++) row[i][j] = false;
    for (let i = 0; i < 11; i ++) for(let j = 0; j < 11; j++) col[i][j] = false;
    for (let i = 0; i <dirs.length; i++) {
        if (dirs[i] == 'L') left();
        if (dirs[i] == 'R') right();
        if (dirs[i] == 'U') up();
        if (dirs[i] == 'D') down();
    }
    for (let i = 0; i < 11; i ++) for (let j = 0; j < 11; j++) if (row[i][j]) answer++;
    for (let i = 0; i < 11; i ++) for(let j = 0; j < 11; j++) if (col[i][j]) answer++;
    return answer;
}
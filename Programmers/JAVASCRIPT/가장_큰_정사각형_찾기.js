const solution = (board) => {
    var answer = 0;
    let x = board.length, y = board[0].length;
    if (x == 1 && y == 1) {
        if (board[x-1][y-1] == 0) return 0;
        else return 1;
    }
    for (let i = 1; i < x; i++) {
        for (let j = 1; j < y; j++) {
            if (board[i][j] == 1) {
                board[i][j] += Math.min(board[i-1][j-1], Math.min(board[i][j-1], board[i-1][j]));
                if (board[i][j] > answer) answer = board[i][j];
            }
        }
    }
    return answer * answer;
}
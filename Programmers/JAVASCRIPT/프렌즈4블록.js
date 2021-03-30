const solution = (m, n, board) => {
    for (let i = 0; i < m; i++) {
        board[i] = board[i].split('');
    }
    let cnt = 0;
    while(1) {
        let board_copy = JSON.parse(JSON.stringify(board));
        for (let i = 0; i < m-1; ++i) {
            for (let j = 0; j < n-1; ++j) {
                if (board[i][j] != '_' && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j] && board[i][j] == board[i+1][j+1]) {
                    board_copy[i][j] = 'z';
                    board_copy[i+1][j] = 'z';
                    board_copy[i][j+1] = 'z';
                    board_copy[i+1][j+1] = 'z';
                }
            }
        }
        let earn = 0;
        for (let i = 0; i < m; ++i) {
            for (let j = 0; j < n; ++j) {
                if (board_copy[i][j]=='z') {
                    if (i != 0) {
                        for (let k = i; k > 0; k--) {
                            let tmp = board[k][j];
                            board[k][j] = board[k-1][j];
                            board[k-1][j] = tmp;
                        }
                    }
                    board[0][j] = '_';
                    ++earn
                }
            }
        }
        console.log('earn ' + earn);
        if (earn == 0) break;
        cnt += earn;        
    }
    return cnt;
}
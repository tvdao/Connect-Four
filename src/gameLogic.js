const initialGrid = () => {
    let board = [];
    for (let row = 0; row < 6; row ++) {
        board.push([]);
        for (let col = 0; col < 7; col++) {
            board[row].push({
                piece: 0,
                row: row,
                col: col
            })
            console.log(board[row][col].piece);
        }
    }
    return board;
}

const placePiece = (board, player, col) => {
    for (let row = 5; row > -1; row--) {
        if (board[row][col].piece === 0) {
            board[row][col].piece = player;
            return true;
        }
    }
    // false means can not place in column
    return false;
}

const horizontalWin = (board, player) => {
    for (let row = 5; row > -1; row--) {
        for (let col = 0; col < 4; col++) {
            if (board[row][col].piece === player &&
                board[row][col+1].piece === player &&
                board[row][col+2].piece === player &&
                board[row][col+3].piece === player) {
                    return true;
            }
        }
    return false;
    }
}

const verticalWin = (board, player) => {
    for (let row = 5; row > 2; row--) {
        for (let col = 0; col < 7; col++) {
            if (board[row][col].piece === player &&
                board[row-1][col].piece === player &&
                board[row-2][col].piece === player &&
                board[row-3][col].piece === player) {
                return true;
            }
        }
    }
    return false;
}

const diagonalWin = (board, player) => {
    for (let row = 5; row > 2; row--) {
        for (let col = 0; col < 7; col++) {
            if (col < 4) {
                if (board[row][col].piece === player &&
                    board[row-1][col+1].piece === player &&
                    board[row-2][col+2].piece === player &&
                    board[row-3][col+3].piece === player) {
                        return true;
                    }
            }
            if (col > 2) {
                if (board[row][col].piece === player &&
                    board[row-1][col-1].piece === player &&
                    board[row-2][col-2].piece === player &&
                    board[row-3][col-3].piece === player) {
                        return true;
                    }
            }
        }
    }
    return false;
}

const checkWin = (board, player) => {
    if (diagonalWin(board, player) || 
        verticalWin(board, player) || 
        horizontalWin(board, player)) {
            return true;
    }
    return false;
}

export {initialGrid, checkWin, placePiece};
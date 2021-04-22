const initialGrid = () => {
    let board = [];
    for (let row = 0; row < 6; row ++) {
        board.push([]);
        for (let col = 0; col < 7; col++) {
            board[row].push({
                player1: false,
                player2: false,
                row: row,
                col: col
            })
        }
    }
    return board;
}

const horizontalWin = () => {

}

const verticalWin = () => {

}

const horizontalWin = () => {
    
}

export {initialGrid};
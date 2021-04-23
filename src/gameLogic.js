/**
 * Filename: gameLogic.js
 * Author: Tri Dao
 * Date: 4/22/21
 * 
 * Summary of File:
 *      This file contains functions that encompass the
 * essential functions of connect 4. Such as, checking 
 * if there is a win in the valid directions, as well as 
 * setting up and updating the board
 */

/**
 * Creates the board, fill with Object that has information
 * of the player(piece) and the corresponding row and col
 * 
 * @return inital Board
 */
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
        }
    }
    return board;
}

/**
 * Place piece of specific player in the column that was clicked,
 * and update the board
 * 
 * @param board - current state of the board
 * @param player - current player that will be assigned at column
 * @param col - columnb where piece will be inserted
 * 
 * @return true if piece is placed, false otherwise
 */
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

/**
 * Check horizontal win based on player
 * 
 * @param board - current state of the board
 * @param player - current player
 * 
 * @return true if win, false otherwise
 */
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

/**
 * Check veritcal win based on player
 * 
 * @param board - current state of the board
 * @param player - current player
 * 
 * @return true if win, false otherwise
 */
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

/**
 * Check diagonal win based on player
 * 
 * @param board - current state of the board
 * @param player - current player
 * 
 * @return true if win, false otherwise
 */
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

/**
 * Checks if there is a win on the board
 * 
 * @param board - current state of the board
 * @param player - current player
 * 
 * @return true if win, false otherwise
 */
const checkWin = (board, player) => {
    if (diagonalWin(board, player) || 
        verticalWin(board, player) || 
        horizontalWin(board, player)) {
            return true;
    }
    return false;
}

export {initialGrid, checkWin, placePiece};
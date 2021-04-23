/**
 * Filename: App.jsx
 * Author: Tri Dao
 * Date: 4/22/21
 * 
 * Summary of File:
 *      This file is the App component. It keeps track of the current board,
 * player, and if there is a winner. This component is the parent component
 * of Board. 
 */

import React, {useState} from "react";
import Board from "./components/Board";
import {initialGrid, checkWin, placePiece} from "./gameLogic"

/**
 * Displays the board and text. Handles the dynamically changes
 * of the board
 * 
 * @return Board component that contains the board of the game and 
 * a resetGame button
 */
const App = () => {
    // Keeps track of board state
    const [board, setBoard] = useState(initialGrid);
    // Keeps track if win
    const [winner, setWinner] = useState(false);
    // Keeps track of current Player
    const [player, setPlayer] = useState(1);
    
    /** 
     * Updates the board by keeping track of players and pieces
     * 
     * @param col - Column where piece will be placed
     */
    const updateBoard = ({col}) => {
        if (!placePiece(board, player, col)) {
            // Column is filled, can't place piece
            return;
        }
        // If win
        if (checkWin(board, player)) {
            setWinner(true);
            return;
        }
        setPlayer(player === 1 ? 2 : 1);
    }

    /** 
     * Clears the board, sets player to 1 and winner to false
     */
    const resetGame = () => (
        <button onClick={() => {
            setBoard(initialGrid);
            setPlayer(1);
            setWinner(false);
        }}>
            Reset Game
        </button>
    )

    return (
        <div>
            <Board 
            board = {board}
            updateBoard = {updateBoard}
            />
            <div>
                <p>{winner ? "Winner: Player " + player : "Next Player: " + player }</p>
                {resetGame()}
            </div>
        </div>
    )
}

export default App;
import React, {useState} from "react";
import Board from "./components/Board";
import {initialGrid, checkWin, placePiece} from "./gameLogic"

function App() {
    const [board, setBoard] = useState(initialGrid);
    const [winner, setWinner] = useState(false);
    const [player, setPlayer] = useState(1);
    
    const updateBoard = ({col, row}) => {
        if (!placePiece(board, player, col)) {
            return;
        }
        if (checkWin(board, player)) {
            setWinner(true);
            return;
        }
        setPlayer(player === 1 ? 2 : 1);
    }

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
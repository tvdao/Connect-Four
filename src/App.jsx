import React, {useState} from "react";
import Board from "./components/Board";
import {initialGrid} from "./gameLogic"

function App() {
    const [board, setBoard] = useState(initialGrid);

    const [player, setPlayer] = useState(false);
    
    const updateBoard = (e) => {
        console.log("row: " + e[0] + " col: " + e[1]);
    }
    return (
        <Board 
            board = {board}
            updateBoard = {updateBoard}
        />
    )
}

export default App;
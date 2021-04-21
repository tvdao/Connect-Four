import React, {useState} from "react";

function App() {

    const [game, setGame] = useState({
        board: [],
        player1: 1,
        player2: 2,
        currentPlayer: null,
        gameOver: false,
        boardRow: 6,
        boardCol: 7
    })

    return (
        <div>
            <h1>Hello World</h1>
            <h1>Hello World</h1>
        </div>
    )
}

export default App;
import React from "react";
import "./cell.css"

const Cell = ({row, col, updateBoard, player1, player2}) => {
    const player = [
        player1 ? "player1" : "",
        player2 ? "player2" : ""
    ]
    return (
        <div className="cell" onClick = {() => {
            updateBoard({
                col: col,
                row: row
            })
        }}>
            <div className="circle">
                <div className={player.join(" ")}></div>
            </div>
        </div>
    )
}

export default Cell;
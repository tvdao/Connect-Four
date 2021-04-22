import React from "react";
import Cell from "./Cell";

const Board = ({board, updateBoard}) => {
    return (
        <div className="board">
            <div className="header"></div>
            {board.map((row, rowId) => {
                return (
                    <div key={rowId}>
                        {row.map((cell, cellId) => {
                            return (
                                <Cell 
                                    key = {cellId}
                                    row = {rowId}
                                    col = {cellId}
                                    updateBoard = {updateBoard}
                                />
                            )
                        })}
                    </div>
                )
            })}
        </div>
    )
}

export default Board;
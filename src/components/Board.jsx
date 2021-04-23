import React from "react";
import Cell from "./Cell";

const Board = ({board, updateBoard}) => {
    return (
        <div className="board">
            {board.map((row, rowId) => {
                return (
                    <div key={rowId}>
                        {row.map((cell, cellId) => {
                            return (
                                <Cell 
                                    piece = {cell.piece}
                                    key = {cellId}
                                    row = {rowId}
                                    col = {cellId}
                                    updateBoard = {updateBoard}
                                    player1 = {cell.piece === 1 ? true : false}
                                    player2 = {cell.piece === 2 ? true: false}
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
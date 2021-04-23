/**
 * Filename: Board.jsx
 * Author: Tri Dao
 * Date: 4/22/21
 * 
 * Summary of File:
 *      This file is the Board component. It maps each spot of the board with
 * a Cell component, passing along data like the piece that occupies the component
 */

import React from "react";
import Cell from "./Cell";

/**
 * Takes the current board and displays each index as a Cell component. 
 * 
 * @param board - current board
 * @param updatedBoard - child function for Cell component
 * 
 * @return a div which encases the entire board and within this div, a cell component
 * for each spot of the board
 */
const Board = ({board, updateBoard}) => {
    return (
        <div className="board">
            {board.map((row, rowId) => {
                return (
                    <div key={rowId}>
                        {/* cell is an object with props(piece, col, row) */}
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
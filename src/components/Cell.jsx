/**
 * Filename: Cell.jsx
 * Author: Tri Dao
 * Date: 4/22/21
 * 
 * Summary of File:
 *      This file is the Cell component. It keeps track of which Cell is clicked
 * and returns that information back up to the App component. It also displays the 
 * pieces on the html page if a player clicked in the Cell.
 */

/**
 * Styles the Cell component as well as displays the pieces within each cell
 * 
 * @param row - row of cell
 * @param col - col of cell
 * @param updateBoard - function to pass data from Cell component to App component
 *                      in order to update the board
 * @param player1 - true if player1 occupies cell
 * @param player2 - true if player2 occupies cell
 * 
 * @return a div that represents the individual cell of the board and an inner div 
 *         which represents the player piece
 */
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
                col: col
            })
        }}>
            <div className="circle">
                <div className={player.join(" ")}></div>
            </div>
        </div>
    )
}

export default Cell;
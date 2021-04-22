import React, {useState} from "react";
import "./cell.css"

const Cell = ({row, col, updateBoard}) => {
    return (
        <div className="cell">
            <div className="circle" onClick= {() => {
                updateBoard([col, row]);
            }}>
                <div ></div>
            </div>
        </div>
    )
}

export default Cell;
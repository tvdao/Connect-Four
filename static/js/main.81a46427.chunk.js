(this.webpackJsonpconnectfour=this.webpackJsonpconnectfour||[]).push([[0],{11:function(e,r,c){"use strict";c.r(r);var t=c(1),n=c(4),i=c.n(n),o=c(2),a=(c(9),c(0)),u=function(e){e.row;var r=e.col,c=e.updateBoard,t=[e.player1?"player1":"",e.player2?"player2":""];return Object(a.jsx)("div",{className:"cell",onClick:function(){c({col:r})},children:Object(a.jsx)("div",{className:"circle",children:Object(a.jsx)("div",{className:t.join(" ")})})})},p=function(e){var r=e.board,c=e.updateBoard;return Object(a.jsx)("div",{className:"board",children:r.map((function(e,r){return Object(a.jsx)("div",{children:e.map((function(e,t){return Object(a.jsx)(u,{piece:e.piece,row:r,col:t,updateBoard:c,player1:1===e.piece,player2:2===e.piece},t)}))},r)}))})},s=function(){for(var e=[],r=0;r<6;r++){e.push([]);for(var c=0;c<7;c++)e[r].push({piece:0,row:r,col:c})}return e},j=function(){var e=Object(t.useState)(s),r=Object(o.a)(e,2),c=r[0],n=r[1],i=Object(t.useState)(!1),u=Object(o.a)(i,2),j=u[0],f=u[1],l=Object(t.useState)(1),d=Object(o.a)(l,2),b=d[0],v=d[1];return Object(a.jsxs)("div",{children:[Object(a.jsx)(p,{board:c,updateBoard:function(e){var r=e.col;(function(e,r,c){for(var t=5;t>-1;t--)if(0===e[t][c].piece)return e[t][c].piece=r,!0;return!1})(c,b,r)&&(!function(e,r){return!!(function(e,r){for(var c=5;c>2;c--)for(var t=0;t<7;t++){if(t<4&&e[c][t].piece===r&&e[c-1][t+1].piece===r&&e[c-2][t+2].piece===r&&e[c-3][t+3].piece===r)return!0;if(t>2&&e[c][t].piece===r&&e[c-1][t-1].piece===r&&e[c-2][t-2].piece===r&&e[c-3][t-3].piece===r)return!0}return!1}(e,r)||function(e,r){for(var c=5;c>2;c--)for(var t=0;t<7;t++)if(e[c][t].piece===r&&e[c-1][t].piece===r&&e[c-2][t].piece===r&&e[c-3][t].piece===r)return!0;return!1}(e,r)||function(e,r){for(var c=5;c>-1;c--){for(var t=0;t<4;t++)if(e[c][t].piece===r&&e[c][t+1].piece===r&&e[c][t+2].piece===r&&e[c][t+3].piece===r)return!0;return!1}}(e,r))}(c,b)?v(1===b?2:1):f(!0))}}),Object(a.jsxs)("div",{children:[Object(a.jsx)("p",{children:j?"Winner: Player "+b:"Next Player: "+b}),Object(a.jsx)("button",{onClick:function(){n(s),v(1),f(!1)},children:"Reset Game"})]})]})},f=function(){return Object(a.jsx)("div",{children:Object(a.jsx)(j,{})})};i.a.render(Object(a.jsx)(f,{}),document.getElementById("root"))},9:function(e,r,c){}},[[11,1,2]]]);
//# sourceMappingURL=main.81a46427.chunk.js.map
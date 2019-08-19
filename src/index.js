import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';

    function Square(props) {
        return (
            <button
              className={props.highlight ? "square-highlighted" : "square-normal"}
              onClick={props.onClick}>
                {props.value}
            </button>
        );
    }

    class Board extends React.Component {
        renderSquare(i) {
            return <Square
                value={this.props.squares[i]}
                onClick={() => this.props.onClick(i)}
                highlight={this.props.winningSpots &&
                    this.props.winningSpots.includes(i)}
            />;
        }

        render() {
            return (
                <div>
                    <div className="board-row">
                        {this.renderSquare(0)}
                        {this.renderSquare(1)}
                        {this.renderSquare(2)}
                    </div>
                    <div className="board-row">
                        {this.renderSquare(3)}
                        {this.renderSquare(4)}
                        {this.renderSquare(5)}
                    </div>
                    <div className="board-row">
                      {this.renderSquare(6)}
                      {this.renderSquare(7)}
                      {this.renderSquare(8)}
                    </div>
                </div>
            );
        }
    }

    class Game extends React.Component {
      constructor(props) {
          super(props);
          this.state = {
              history: [{
                  squares: Array(9).fill(null),
              }],
              winningSpots: null,
              stepNumber: 0,
              xIsNext: true,
          }
      }

      nextPlayer() {
          return this.state.xIsNext ? 'X' : 'O';
      }

      handleClick(i) {
          const history = this.state.history.slice(0, this.state.stepNumber + 1);
          const current = history[history.length-1];
          const squares = current.squares.slice();
          if (squares[i] || this.state.winningSpots) {
              return;
          }
          squares[i] = this.nextPlayer();
          this.setState({
              history: history.concat([{
                  squares: squares,
              }]),
              stepNumber: history.length,
              xIsNext: !this.state.xIsNext,
          });
          const winner = calculateWinner(squares);
          if (winner) {
              this.setState({
                  winningSpots: winner,
              })
          }
      }

    jumpTo(step) {
        if (step < this.state.stepNumber) {
            this.setState({
              stepNumber: step,
              xIsNext: (step%2) === 0,
              winningSpots: null,
            });
        }
        
    }

    render() {
        const history = this.state.history;
        const current = history[this.state.stepNumber];

        const moves = history.map((step, move) => {
            const desc = move ?
                'Go to move #' + move :
                'Go to game start';
            return (
                <li key={move}>
                    <button onClick={() => this.jumpTo(move)}>{desc}</button>
                </li>
            )
        })

        let status;
        if (this.state.winningSpots) {
            status = 'Winner: ' + current.squares[this.state.winningSpots[0]];
        } else {
            status = 'Next player: ' + this.nextPlayer();
        }

        return (
            <div className="game">
                <div className="game-board">
                    <Board 
                        squares={current.squares}
                        onClick={(i) => this.handleClick(i)}
                        winningSpots={this.winningSpots}
                    />
                </div>
                <div className="game-info">
                    <div>{status}</div>
                    <ol>{moves}</ol>
                </div>
            </div>
        );
    }
  }

  function calculateWinner(squares) {
      const lines = [
          [0, 1, 2],
          [3, 4, 5],
          [6, 7, 8],
          [0, 3, 6],
          [1, 4, 7],
          [2, 5, 8],
          [0, 4, 8],
          [2, 4, 6],
      ];
      for (let i = 0; i < lines.length; i++) {
          const [a, b, c] = lines[i];
          if (squares[a] && squares[a] === squares[b] && squares[a] === squares[c]) {
              return lines[i];
          }
      }
      return null;
  }
  
  // ========================================
  
  ReactDOM.render(
      <Game />,
      document.getElementById('root')
  );
  
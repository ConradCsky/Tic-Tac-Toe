# Tic Tac Toe
This is a simple implementation of the popular Tic-Tac-Toe game in C++. The game allows two players, using 'X' and 'O' symbols, to take turns placing their symbols on a 3x3 grid. The goal of the game is for a player to form a horizontal, vertical, or diagonal line of three of their symbols. The game ends when one of the players wins or the grid is full, resulting in a draw.

The code is structured into the following functions:

    isBoardFull(): Checks if the board is full, indicating a draw.
    checkWin(): Checks if any player has won by forming a line of their symbols.
    printBoard(): Displays the current state of the board.
    makeMove(int pos): Makes a move for the current player at the specified position (if valid).

The main() function contains the game loop, which repeatedly prompts players for input and updates the board until the game ends. The code also includes input validation to handle incorrect inputs (e.g., characters and numbers outside the range of 1-9).

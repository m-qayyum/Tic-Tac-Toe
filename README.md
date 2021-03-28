# Tic-Tac-Toe

A C programming language program using functions, arrays(multidimensional arrays) and traversing multidimensional arrays in order to design simple algorithms and pass arrays to functions.

Properties:

Initialize a Tic-Tac-Toe board.
“The board is a 2D array of size 3x3. The function will set an id for each cell of the board starting from 1 and stop at 9.”

Print a Tic-Tac-Toe board.

Create a Tic-Tac-Toe board.
“The function allows the user to create a board and set some X or O on the board at any cell.”

Check Validity of the user input. 
“If the user typed any invalid input like cell number 21 or rather than entering X or O the user typed C the function should ignore his input and ask him to enter a valid input.”

Check if a given Tic-Tac-Toe board is a valid board or an invalid board.
“The board is valid if it is an empty board or if the difference between the total number of X and the total number of O symbols on the board is 0 or 1.”

Check if any next move or next play for any player X or O who has the turn to play is winning move.
“The function will print the cell number or ID that if the player places an X or O in it he/she will win the game. If there is more than one cell where the player could place his symbol in and win the game the function should print all the winning cells for that player.”

Check which player (player X or O) has won the game (if any).
“use recursion to implement this function. If there is no winner the function will return 'D' otherwise return the winner symbol, either 'X' or 'O'.”

Display a menu for the user and asks him to select which function he/she wants to test.

Functions Used: 

“void InitializeBoard, void PrintBoard, void CreateBoard, int IsValidBoard, void ListWinningCells, char WhoIsTheWinner.”

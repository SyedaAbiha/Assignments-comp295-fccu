# Assignments-comp295-fccu
---------------------------
2048 Game in C++ (Complete)
---------------------------
This repository contains a command line version of the popular 2048 game written in C++. The game is played on a 4x4 board where tiles with the same number merge into a single tile with the sum of the two tiles.

Requirements
g++ compiler
Windows operating system
How to run
Clone the repository to your local machine.
Open a terminal and navigate to the repository folder.
Compile the program by running g++ Assignment1_231522019_Abiha.cpp -o 2048.exe in the terminal.
Run the program by running 2048.exe.
How to play
Use the arrow keys to move the tiles.
Tiles with the same number merge into a single tile with the sum of the two tiles.
The game is won when a tile with the number 2048 appears on the board.
The game is lost when there are no more moves possible.
Code Documentation
The code contains the following functions:

initBoard()
Function to initialize the main board (the starting)

displayBoard()
Function to display the board on the console.

isGameOver()
Function to check if the game is over. The game is over if there are no more moves possible or a tile with the number 2048 appears on the board.

addNewTile()
Function to add a new random tile (with either 2 or 4) to the board.

main()
The main function that runs the game. It calls the other functions in a loop until the game is over.

Global Variables
fixed_size: The size of the board, initialized to 4.
board: A 2D array to hold the values of the tiles on the board.
score: The current score of the game.
highScore: The highest score achieved in the current session of the game.

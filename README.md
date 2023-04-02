# Assignments-comp295-fccu
---------------------------
2048 Game in C++ (Complete)
---------------------------
This is a simple implementation of the popular 2048 game, coded in C++. The game is played on a 4x4 grid where the player needs to combine the numbered tiles (starting from 2) to create a tile with the value of 2048.

**Requirements:**

- C++ compiler
- Windows OS (To run the .exe file)

**How to run:**

- Download the file 'Assignment1_231522019_Abiha.cpp' to your device.
- Open a terminal and 'cd' to the folder it was downloaded.
- Compile the program by running 'g++ Assignment1_231522019_Abiha.cpp' -o 2048.exe in the terminal.
- Run the program by running 2048.exe.

**How to play:**

- Use the arrow keys to move the tiles.
- Tiles with the same number merge into a single tile with the sum of the two tiles.
- The game is won when a tile with the number 2048 appears on the board.
- The game is lost when there are no more moves possible.

**Code Documentation:
The code contains the following functions:**

- initBoard()

Function to initialize the main board (the starting). Initializes every row and column with 0. Adds two random tiles initially on the boad when the game starts of value of either 2 or 4. The tiles are placed in two random positions on the board.

- displayBoard()

This function displays the current state of the game board in the console. The function also displays the player's score and high score. It replaces every 0 with an empty space when user start the game.

- isGameOver()

Function to check if the game is over. The game is over if there are no more moves possible or a tile with the number 2048 appears on the board.

- addNewTile()

Function to add a new random tile (with either 2 or 4) to the board. It creates an array that stores the location of empty cells in the board (locations of '0's).
Then it generates a value of either '2' or '4' by randomly selecting one of those empty tiles' location

- moveTiles()

This function is responsible for moving the tiles in the specified direction (up, down, left, or right) based on the player's input. When two tiles with the same number are adjacent to each other in the direction of the move, they will be merged into one tile with the sum of the two tiles.

- mainLoop()

This function is the main loop of the game, which takes input from the player and updates the game state based on the input. The function also checks if the game is over and displays the game board after each move.

- main()

The main function that runs the game. It displays the main menu, through which the user calls the other functions in a loop until they quit.

**Global Variables:**

- fixed_size: The size of the board, initialized to 4.
- board: A 2D array to hold the values of the tiles on the board.
- score: The current score of the game.
- highScore: The highest score achieved in the current session of the game.

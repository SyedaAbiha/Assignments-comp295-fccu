/*
Name: Umm-e-Abiha
Roll#: 231522019
GitHub Repo Url: https://github.com/SyedaAbiha/Assignments-comp295-fccu
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// USE THIS TO COMPILE: g++ Assignment1_231522019_Abiha.cpp -o 2048.exe

const int fixed_size = 4;                // Initializing a constant on which the main game mechanics will be based
 
int board[fixed_size][fixed_size]; // Initializing the board with the specified matrix size (4x4)

int score = 0;                     // Score variable which will be used throughout to store points per game
int highScore = 0;                 // High score to save the highest score throughout the played games in one instance

// Function to initialize the main board (the starting)
void initBoard() { 
    // Initialize all elements to 0
    for (int i = 0; i < fixed_size; i++) {     // for i in range(fixed_size) [ROWS]
        for (int j = 0; j < fixed_size; j++) { // for j in range(fixed_size) [COLUMNS]
            board[i][j] = 0;                   // Setting all elements to value '0'
        }
    }
    // Adding two random tiles
    srand(time(0));
    // Tile-1 'x' and 'y'
    int x1 = rand() % fixed_size; 
    int y1 = rand() % fixed_size;
    // Tile-2 'x' and 'y'
    int x2 = rand() % fixed_size;
    int y2 = rand() % fixed_size;

    while (x1 == x2 && y1 == y2) { // Ensure that the two random tiles are not the same
        // If they are same, change the value of the other
        x2 = rand() % fixed_size;
        y2 = rand() % fixed_size;
    }
    // Setting random values (2 or 4) in those selected random tiles
    board[x1][y1] = (rand() % 2 + 1) * 2; 
    board[x2][y2] = (rand() % 2 + 1) * 2;
}

// Function to display the board on the console
void displayBoard() {
    system("cls"); // Clearing the console (purging previous output)    
    cout << "Score: " << score << "|  High Score: " << highScore << "\n=========================\n";
    for (int i = 0; i < fixed_size; i++) {     // for i in range(fixed_size) [ROWS]
        for (int j = 0; j < fixed_size; j++) { // for j in range(fixed_size) [COLUMNS]
            int tile = board[i][j];
            if (tile == 0) {
                cout << "|     ";
            } else {
                cout << "|  " << board[i][j] << "  ";
            }
        }
        cout << "|\n-------------------------" << endl;
    }        
    cout << "\nTIP: Use Arrow Keys to Move.";
}

bool isGameOver() {
    // Game is over if a 2048 tile is detected
    for (int i = 0; i < fixed_size; i++) {     // for i in range(fixed_size) [ROWS]
        for (int j = 0; j < fixed_size; j++) { // for j in range(fixed_size) [COLUMNS]
            if (board[i][j] == 2048) {
                return true;
            }
        }
    }

    // Game is over if there are no more moves possible
    for (int i = 0; i < fixed_size; i++) {     // for i in range(fixed_size) [ROWS]
        for (int j = 0; j < fixed_size; j++) { // for j in range(fixed_size) [COLUMNS]
            // GAME is NOT over IF
            if (board[i][j] == 0) { // There are empty spaces to be filled
                return false;
            }
            // There is a matching tile above or to the left, the game is not over
            if (i != 0 && board[i][j] == board[i - 1][j]) { // Above
                return false;
            }
            if (j != 0 && board[i][j] == board[i][j - 1]) { // Left
                return false;
            }
            // There is a matching tile below or to the right, the game is not over
            if (i != fixed_size - 1 && board[i][j] == board[i + 1][j]) { // Below
                return false;
            }
            if (j != fixed_size - 1 && board[i][j] == board[i][j + 1]) { // Right 
                return false;
            }
        }
    }

    // If the code reaches here, there are no empty spaces and no matching tiles, the game is over
    return true;
}

// Function to add a new random tile (with either 2 or 4) to the board
void addNewTile() {
    // Find all empty cells within the board

    int emptyCells[fixed_size * fixed_size][2]; // An Array which visually tells us location of empty cells (0s) starting from the top left, going towards bottom right
    int count = 0; // 
    for (int i = 0; i < fixed_size; i++) {      // for i in range(fixed_size) [ROWS]
        for (int j = 0; j < fixed_size; j++) {  // for j in range(fixed_size) [COLUMNS]
            if (board[i][j] == 0) {             // If empty cell is detected
                emptyCells[count][0] = i;       // Store its 'x' position
                emptyCells[count][1] = j;       // Store its 'y' position
                count++;
            }
        }
    }

    // Choose a random empty cell and add a new tile
    srand(time(NULL));
    int randomIndex = rand() % count;
    int randomValue = (rand() % 2 + 1) * 2; // Generates either 2 or 4
    int row = emptyCells[randomIndex][0]; 
    int col = emptyCells[randomIndex][1];
    board[row][col] = randomValue; // Setting the random value to the random empty cell.
}

// Function which takes info from keyborad input and moves the tiles within the board (respectively)
void moveTiles(int board[fixed_size][fixed_size], int& score, int rowDirr, int colDirr) { // rowDirr and colDirr specify which direction to move
    bool isMoved = false;

    // Slide tiles as far as possible in the given direction
    for (int times = 0; times < 4; times++) {       // to make sure it slides all tiles
        for (int i = 0; i < fixed_size; i++) {      // for i in range(fixed_size) [ROWS]
            for (int j = 0; j < fixed_size; j++) {  // for j in range(fixed_size) [COLUMNS]
                // Finding the new position for the selected tile
                int newRow = i + rowDirr;  
                int newCol = j + colDirr;

                // Check if tile is not empty and new position is within the board
                if (board[i][j] != 0 && newRow >= 0 && newRow < fixed_size && newCol >= 0 && newCol < fixed_size) {
                    // Keep sliding the tile until it reaches an empty spot or a tile with a different value
                    while (newRow >= 0 && newRow < fixed_size && newCol >= 0 && newCol < fixed_size) {
                        if (board[newRow][newCol] == 0) {
                            // Slide tile to new position
                            board[newRow][newCol] = board[i][j];
                            board[i][j] = 0;
                            i = newRow;
                            j = newCol;
                            newRow += rowDirr;
                            newCol += colDirr;
                            isMoved = true; // A tile has been moved
                        }
                        else if (board[newRow][newCol] == board[i][j]) {
                            // Merge tiles with same value
                            board[newRow][newCol] += board[i][j];
                            score += board[newRow][newCol]; // Add merged tile value to the score
                            board[i][j] = 0;
                            isMoved = true; // A tile has been moved
                            break;
                        }
                        else {
                            // Stop sliding
                            break;
                        }
                    }
                }
            }
        }
    }
    // Add a new tile if any tiles were moved 
    if (isMoved) { // only adding in case tiles were moved, unless adding at all times makes it messy and unplayable
        addNewTile(); // Add a new tile to the board
    }
}

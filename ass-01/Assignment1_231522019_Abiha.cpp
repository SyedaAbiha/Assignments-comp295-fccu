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

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

# Guessing Game with High Score Tracker
This is a simple C++ program that allows you to play a guessing game and keeps track of high scores.

## How to Run the Program
- To run the program, you'll need to compile the source code using a C++ compiler, such as g++ or clang++. Here's an example command to compile the program using g++:
- This will create an executable file called guessing_game in the current directory. 

## How to Play the Game
- When you run the program, it will display the current high scores, if any. 
- To play the game, simply follow the prompts on the console to enter your guesses for the random number between 1 and 10.
- If you correctly guess the number, the program will ask for your name and add your score to the high scores list. 
- The high scores list is sorted by score in descending order, so the highest score is at the top.
- The high scores are saved to a text file called highscores.txt in the same directory as the executable. 
- If this file doesn't exist, it will be created the first time the program saves the high scores.

## Modifying the Program
- If you want to modify the program, you can edit the source code in the guessing_game.cpp file. Here are some things you might want to change:
- The range of the random number. You can modify the rand() % 10 + 1 expression to generate a random number in a different range.
- The high scores file name or location. You can modify the writeHighScores() function to write the high scores to a different file, or change the file name in the ifstream and ofstream constructors.
- The way the high scores are displayed. You can modify the displayHighScores() function to change the format of the high scores output.

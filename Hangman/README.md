# Hangman Game in C++
This is a simple implementation of the popular hangman game in C++. The game randomly selects a word from a predefined list and prompts the user to guess letters until they either guess the entire word or exceed a maximum number of incorrect guesses.

## How to Run the Game
- Ensure you have a C++ compiler installed on your system.
- Download or clone the source code from this repository.
- Navigate to the directory containing the source code in your terminal or command prompt.
- Compile the source code using the following command: g++ hangman.cpp -o hangman
- Run the compiled program by executing the following command: ./hangman

## How to Play
- The game will prompt you with the number of incorrect guesses remaining and the letters you have already guessed.
- You will see a series of dashes that represent the letters of the word you are trying to guess. Guess letters by typing them and pressing enter.
- If the letter you guessed is in the word, the program will fill in the corresponding dashes with that letter.
- If the letter you guessed is not in the word, the program will indicate that you have made an incorrect guess and decrement the number of incorrect guesses remaining.
- Continue guessing letters until you either correctly guess the entire word or exceed the maximum number of incorrect guesses.

## Customizing the Game
You can modify the list of words in the words vector to include your own words, or even load the words from a file. You can also change the maximum number of incorrect guesses allowed by modifying the MAX_WRONG constant. Additionally, you can add more features to the game, such as displaying a hangman figure or allowing the user to play again after the game ends.

## License
This project is licensed under the MIT License. Feel free to use and modify the code as you see fit.

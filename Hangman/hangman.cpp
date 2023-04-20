#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const int MAX_WRONG = 8;  // maximum number of incorrect guesses allowed

    vector<string> words; // collection of possible words to guess
    words.push_back("PROGRAM");
    words.push_back("COMPUTER");
    words.push_back("SOFTWARE");
    words.push_back("HARDWARE");
    words.push_back("DATABASE");
    words.push_back("NETWORK");
    words.push_back("KEYBOARD");
    words.push_back("MOUSE");

    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());

    const string THE_WORD = words[0]; // word to guess
    int wrong = 0; // number of incorrect guesses
    string soFar(THE_WORD.size(), '-'); // word guessed so far
    string used = ""; // letters already guessed

    cout << "Welcome to Hangman. Good luck!\n";

    // main loop
    while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
        cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
        cout << "\nYou've used the following letters:\n" << used << endl;
        cout << "\nSo far, the word is:\n" << soFar << endl;

        char guess;
        cout << "\n\nEnter your guess: ";
        cin >> guess;
        guess = toupper(guess); // make uppercase since words are in uppercase

        while (used.find(guess) != string::npos) {
            cout << "\nYou've already guessed " << guess << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = toupper(guess);
        }

        used += guess;

        if (THE_WORD.find(guess) != string::npos) {
            cout << "\nThat's right! " << guess << " is in the word.\n";

            // update soFar to include newly guessed letter
            for (int i = 0; i < THE_WORD.length(); ++i) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        }
        else {
            cout << "\nSorry, " << guess << " isn't in the word.\n";
            ++wrong;
        }
    }

    // end of game loop
    if (wrong == MAX_WRONG) {
        cout << "\n\nYou've been hanged!";
    }
    else {
        cout << "\n\nYou guessed it!";
    }

    cout << "\nThe word was " << THE_WORD << endl;

    return 0;
}


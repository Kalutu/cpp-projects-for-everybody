#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Score {
    string name;
    int score;
};

bool compareScores(const Score& a, const Score& b) {
    return a.score > b.score;
}

void displayHighScores(const vector<Score>& scores) {
    cout << "High Scores:" << endl;
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }
}

void writeHighScores(const vector<Score>& scores, const string& filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (int i = 0; i < scores.size(); i++) {
            outfile << scores[i].name << " " << scores[i].score << endl;
        }
        outfile.close();
    }
}

int main() {
    srand(time(NULL));  // Initialize random number generator

    vector<Score> scores;

    ifstream infile("highscores.txt");
    if (infile.is_open()) {
        string name;
        int score;
        while (infile >> name >> score) {
            Score s = { name, score };
            scores.push_back(s);
        }
        infile.close();
    }

    displayHighScores(scores);

    int randomNumber = rand() % 100 + 1;  // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the guessing game! Try to guess the number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low. Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high. Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            string name;
            cout << "Enter your name for the high scores list: ";
            cin >> name;
            Score s = { name, attempts };
            scores.push_back(s);
            sort(scores.begin(), scores.end(), compareScores);
            writeHighScores(scores, "highscores.txt");
            displayHighScores(scores);
        }
    } while (guess != randomNumber);

    return 0;
}

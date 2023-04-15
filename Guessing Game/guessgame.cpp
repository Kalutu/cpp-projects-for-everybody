#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Score {
    string name;
    int score;
};

bool compareScores(const Score& a, const Score& b) {
    return a.score > b.score;
}

int main() {
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

    cout << "High Scores:" << endl;
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }

    string name;
    int score;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your score: ";
    cin >> score;

    Score s = { name, score };
    scores.push_back(s);

    sort(scores.begin(), scores.end(), compareScores);

    ofstream outfile("highscores.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < scores.size(); i++) {
            outfile << scores[i].name << " " << scores[i].score << endl;
        }
        outfile.close();
    }

    cout << "High Scores:" << endl;
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i].name << ": " << scores[i].score << endl;
    }

    return 0;
}

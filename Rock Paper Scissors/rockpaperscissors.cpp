#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int player_choice, computer_choice;
    srand(time(NULL)); // Seed random number generator
    
    cout << "Let's play Rock Paper Scissors!\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n";
    cout << "Enter your choice (1-3): ";
    cin >> player_choice;
    
    // Generate computer choice
    computer_choice = rand() % 3 + 1;
    
    // Determine winner
    if (player_choice == computer_choice) {
        cout << "It's a tie!\n";
    } else if ((player_choice == 1 && computer_choice == 3) ||
               (player_choice == 2 && computer_choice == 1) ||
               (player_choice == 3 && computer_choice == 2)) {
        cout << "You win!\n";
    } else {
        cout << "Computer wins!\n";
    }
    
    return 0;
}


#include <iostream>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()
using namespace std;

void playGame(int secret, int attempts = 1) {
    int guess, bulls = 0, cows = 0;

    cout << "Enter a 4-digit number: ";
    cin >> guess;

    int tempSecret = secret, tempGuess = guess;

    
    for (int i = 0; i < 4; ++i) {
        if (tempSecret % 10 == tempGuess % 10)
            ++cows;
        tempSecret /= 10;
        tempGuess /= 10;
    }

    tempSecret = secret;
    tempGuess = guess;

    for (int i = 0; i < 4; ++i) {
        int digitGuess = tempGuess % 10;
        int copySecret = secret;
        for (int j = 0; j < 4; ++j) {
            if (digitGuess == copySecret % 10) {
                ++bulls;
                break;
            }
            copySecret /= 10;
        }
        tempGuess /= 10;
    }

    bulls -= cows; 

    
    cout << "Bulls: " << bulls << ", Cows: " << cows << endl;

    if (cows == 4) {
        cout << "Congratulations! You've guessed the number in " << attempts << " attempts!" << endl;
        return;
    }

    playGame(secret, attempts + 1); 
}

int main() {
    srand(time(0));
    int secret = 1000 + rand() % 9000; 

    cout << "Welcome to Bulls and Cows! Try to guess the 4-digit number." << endl;

    playGame(secret); 

    return 0;
}


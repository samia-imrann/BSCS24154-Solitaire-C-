#include<iostream>
#include"game.h"
using namespace std;

int main() 
{
    bool playAgain = true;

    while (playAgain) {
        cout << "- - - - - - - - - - - - - - - - - - - - - - -  WELCOME TO SOLITAIRE - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl << endl
            << "- - - - - - - - - - - - - - - - - - - - - - - - - - GAME RULES - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "1) For stock: use cmd 's'" << endl;
        cout << "2) For moving cards: use cmd 'm (source) (destination) (number of Cards)'" << endl;
        cout << "3) For undo: use 'z'" << endl;
        cout << "4) To quit the game use 'quit' or 'end'" << endl;
        cout << "5) To win the game all cards must be in foundations" << endl << endl;
        cout << " BEST OF LUCK !!!" << endl;
        cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;

        game solitaire;
        solitaire.initializeGame();
        solitaire.gameDisplay();

        bool gameRunning = true;

        while (gameRunning) {
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;

            string command;
            cout << "Enter a command: ";
            getline(cin, command);
            cout << endl;
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;

            if (command == "z") {
                solitaire.undo();
            }
            else if (command == "s") {
                bool check = solitaire.drawCard(command);
                if (!check) {
                    solitaire.refreshStock();
                }
            }
            else if (command == "quit" || command == "end") {
                cout << "- - - - - - - - - - - - - - - - - - - - USER HAS ENDED THE GAME - - - - - - - - - - - - - - - - - - - -" << endl;

                string ans;
                while (true) {
                    cout << "DO YOU WANT TO PLAY AGAIN? (Y/N): ";
                    getline(cin, ans);

                    if (ans == "Y" || ans == "y") {
                        system("cls");
                        break; // break inner loop to restart game
                    }
                    else if (ans == "N" || ans == "n") {
                        gameRunning = false;
                        playAgain = false;
                        break;
                    }
                    else {
                        cout << "Invalid answer !!!" << endl;
                    }
                }
            }
            else {
                if (!solitaire.validCommand(command)) {
                    cout << "Invalid command. Try again!" << endl;
                }
                else {
                    bool success = solitaire.performCommand();
                    if (!success) {
                        cout << "Move could not be completed. Try again!" << endl;
                    }
                }
            }

            if (!playAgain || !gameRunning) {
                break;
            }

            solitaire.gameDisplay();

            if (solitaire.gameWon()) {
                cout << "- - - - - - - - - - - - - - - - - - - - THE GAME HAS BEEN WON...!!! - - - - - - - - - - - - - - - - - - - - " << endl;

                string ans;
                while (true) {
                    cout << "DO YOU WANT TO PLAY AGAIN? (Y/N): ";
                    getline(cin, ans);

                    if (ans == "Y" || ans == "y") {
                        system("cls");
                        break; // restart game
                    }
                    else if (ans == "N" || ans == "n") {
                        gameRunning = false;
                        playAgain = false;
                        break;
                    }
                    else {
                        cout << "Invalid answer !!!" << endl;
                    }
                }
            }
        }
    }

    system("pause");
    return 0;
}

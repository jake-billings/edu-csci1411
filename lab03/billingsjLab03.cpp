/* Name: Jake Billings
   Class: CSCI 1411-00X
   Description: Scores multiple rock paper scissors games
   Lab Partner: Matt Hanford
   Status: successfully compiled and run on csegrid
*/

//Include cin, cout
#include <iostream>

//Use the standard namespace
using namespace std;

//Define constants to represent the application state
const int INVALID_PLAYER_2 = -2;
const int INVALID_PLAYER_1 = -1;
const int TIE = 0;
const int WIN_PLAYER_1 = 1;
const int WIN_PLAYER_2 = 2;

//Define the main function
int main() {
    //Declare a space in memory to store user input
    char inputContinue;
    
    //Declare a do, while loop to play one game then conditionally loop
    do {
        char inputPlayer1, inputPlayer2;

        //Collect player 1's char input
        cout << "Player 1, what pick rock, paper, or scissors (r, p, s)" << endl;
        cin >> inputPlayer1;
        cout << endl;
        
        //Collect player 2's char input
        cout << "Player 2, what pick rock, paper, or scissors (r, p, s)" << endl;
        cin >> inputPlayer2;
        cout << endl;
        
        //Declare a space in loop-scope memore to store the state of the current game
        int state = -4;
        
        //Cut the cases in half by converting all uppercase entries to lowercase
	inputPlayer1 = tolower(inputPlayer1);
        inputPlayer2 = tolower(inputPlayer2);
        
        //Cover three cases in one check by checking for a tie ahead of time.
        if (inputPlayer1 == inputPlayer2) {
            state = TIE;
        } else {
            //Cover the six cases in which players win and the 6 cases of invalid input usings switches and ifs
            switch (inputPlayer1) {
                //Check if player 1 selected r
                case 'r':
                    //If player 1 selected r and player 2 selected s, player 1 wins
                    if (inputPlayer2=='s') {
                        state = WIN_PLAYER_1;
                        break;
                    }
                    //If player 1 selected r and player 2 selected p, player 2 wins
                    if (inputPlayer2=='p') {
                        state = WIN_PLAYER_2;
                        break;
                    }
                    //If there is not a tie, player 2 did not select r. If player 2 also didn't select p or s, it's not a valid selection.
                    state = INVALID_PLAYER_2;
                    break; //Unrecognized input for player2
                //Check if player 1 selected p
                case 'p':
                    //If player 1 selected r and player 2 selected r, player 1 wins
                    if (inputPlayer2=='r') {
                        state = WIN_PLAYER_1;
                        break;
                    }
                    //If player 1 selected s and player 2 selected p, player 2 wins
                    if (inputPlayer2=='s') {
                        state = WIN_PLAYER_2;
                        break;
                    }
                    //If there is not a tie, player 2 did not select p. If player 2 also didn't select r or s, it's not a valid selection.
                    state = INVALID_PLAYER_2;
                    break; //Unrecognized input for player2
                //Check if player 1 selected s
                case 's':
                    //If player 1 selected s and player 2 selected p, player 1 wins
                    if (inputPlayer2=='p') {
                        state = WIN_PLAYER_1;
                        break;
                    }
                    //If player 1 selected s and player 2 selected r, player 2 wins
                    if (inputPlayer2=='r') {
                        state = WIN_PLAYER_2;
                        break;
                    }
                    //If there is not a tie, player 2 did not select s. If player 2 also didn't select r or p, it's not a valid selection.
                    state = INVALID_PLAYER_2;           
                    break; //Unrecognized input for player2 
                //If player 1 didn't select r, p, or s, player 1's selection is invalid.
                default:
                    state = INVALID_PLAYER_1; //Unrecognized input for player1
            }
        }
        
        //Based on the result state, print the appropriate message.
        switch (state) {
            case TIE:
                cout << "Tie! Neither player 1 nor player 2 wins!" << endl;
                break;
            case WIN_PLAYER_1:
                cout << "Player 1 wins!" << endl;
                break;
            case WIN_PLAYER_2:
                cout << "Player 2 wins!" << endl;
                break;
            case INVALID_PLAYER_1:
                cout << "Player 1 entered an invalid move." << endl;
                break;
            case INVALID_PLAYER_2:
                cout << "Player 2 entered an invalid move." << endl;
                break;
            default:
                cout << "Unknown error; this should never happen." << endl;
        }

        cout << endl;        
 
        //Ask the user if he/she would like to play again.       
        cout << "Would you like to play again? (y/n)" << endl;
        //Store the value.
        cin >> inputContinue;
        if (inputContinue=='Y') inputContinue='y';
    } while (inputContinue=='y');
}

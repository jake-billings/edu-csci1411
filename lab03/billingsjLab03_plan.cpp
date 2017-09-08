//Include cin, cout
//Use the standard namespace
//Define constants to represent the application state
//Define the main function
    //Declare a space in memory to store user input
    //Declare a do, while loop to play one game then conditionally loop
        //Collect player 1's char input
        //Collect player 2's char input
        //Declare a space in loop-scope memore to store the state of the current game
        //Cut the cases in half by converting all uppercase entries to lowercase
        //Cover three cases in one check by checking for a tie ahead of time.
            //Cover the six cases in which players win and the 6 cases of invalid input usings switches and ifs
                //Check if player 1 selected r
                    //If player 1 selected r and player 2 selected s, player 1 wins
                    //If player 1 selected r and player 2 selected p, player 2 wins
                    //If there is not a tie, player 2 did not select r. If player 2 also didn't select p or s, it's not a valid selection.
                    break; //Unrecognized input for player2
                //Check if player 1 selected p
                    //If player 1 selected r and player 2 selected r, player 1 wins
                    //If player 1 selected s and player 2 selected p, player 2 wins
                    //If there is not a tie, player 2 did not select p. If player 2 also didn't select r or s, it's not a valid selection.
                    break; //Unrecognized input for player2
                //Check if player 1 selected s
                    //If player 1 selected s and player 2 selected p, player 1 wins
                    //If player 1 selected s and player 2 selected r, player 2 wins
                    //If there is not a tie, player 2 did not select s. If player 2 also didn't select r or p, it's not a valid selection.
                    break; //Unrecognized input for player2 
                //If player 1 didn't select r, p, or s, player 1's selection is invalid.
                    state = INVALID_PLAYER_1; //Unrecognized input for player1
        //Based on the result state, print the appropriate message.
        //Ask the user if he/she would like to play again.       
        //Store the value.

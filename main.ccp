#include <iostream>
using namespace std;

int main()  {
    bool newGame = false;
    bool loadGame = false;

    string progress = "";

    bool menu = false;
    int menuChoice = 0;

    // title card

    cout << "  __                _  o         __    _              _             "      << endl;
    cout << " /_`) __  _    ___ )L  _  __    /_`) __))__ _ __ _ _  )L _    __  __"      << endl;
    cout << "(( ( ((_)((_( ((_( (( (( ((_   (( ( ((_( \\(/'(('((\\( (( ((_( (|  (('"    << endl;
    cout << "       ))                                                          "       << endl;
    cout << endl;
    cout << "                        by TwoHeadedShark                          "       << endl;
    cout << endl;

    // initial menu (switch statement)

    do {                            /* while menu != true, do this: */
        cout << "1) Start New Game" << endl;
        cout << "2) Load Previous Game" << endl;
        cout << "Enter choice [1, 2]: " << endl;
        cin >> menuChoice;
        switch (menuChoice) {
            case 1:                 /* if menuChoice == 1 */
                // TODO: check that file exists/is empty, if yes, ask "This will erase previous game progress. Continue?" if yes, then continue, if no, break
                newGame = true;
                menu = true;
                progress = "S";     /* S = start game */
                break;              /* skips to while () */
            
            case 2:                 /* if menuChoice == 2 */
                // TODO: check if file exists/is empty, if not exist, print "Oops, no saved game progress found. Try again!" and break. if exist, loadgame = true
                loadGame = true;
                // TODO: progress = fileProgress;
                break;

            default:                /* if menuChoice != case 1 || menuChoice != case 2 */
                cout << endl;
                cout << "Invalid option, try again!" << endl;
                cout << endl;
                break;
        }
    } while (!menu);

    // if newgame = true
        // if file is written to, reset file io to empty (resets game progress)
        // ask for name input
        // write name to file
        // set PROG = 1; (PROG gets incremented per reef explored)

    // if loadgame = true
        // if file is empty, return error and loop back to beginning
        // if file is written to, use file stats to write to game stats
        // skip to reef that matches PROG

    // if PROG = 1;
        // spawn random crew members (5-15)
        // spawn random air (5-15)
        // spawn random fuel (5-15)
        // submarine menu [cargosubmarine, gasomarine, oxygenarine]
        // add sub stats to random spawns
        // write^ to file
        // PROG+1;
    
    // if PROG = 2;
    

    

    return 0;
}
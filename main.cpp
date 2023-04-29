#include <iostream>                         /* allows user input and output */
#include <fstream>                          /* allows file input and output */
#include <cstdlib>                          /* allows rand() */
#include <string>
using namespace std;

#include "Submarine.h"

int main()  {

    // file io 1

    string line;
    int lineCount = 0;

    const string FILENAME = "savefile.txt";
    ifstream fin(FILENAME);                 /* read from file */
    ofstream fout(FILENAME);                /* write to file */

    if (!fin.is_open()) {                   /* if file does not exist */
        cout << endl; cout << "How did you manage to get this error..." << endl; cout << endl;
        exit(2);
    }

    fout << "s" << endl;   // DELETE ME !!!!!
    fout << "Jack Sparrow" << endl;

    while (fin >> line) {                   /* for each line received from file, increment lineCount */
        lineCount++;
    }

    fin.close();                            /* close read from file */
    fout.close();                           /* close write to file */

    // title card

    cout << "  __                _  o         __    _              _             "      << endl;
    cout << " /_`) __  _    ___ )L  _  __    /_`) __))__ _ __ _ _  )L _    __  __"      << endl;
    cout << "(( ( ((_)((_( ((_( (( (( ((_   (( ( ((_( \\(/'(('((\\( (( ((_( (|  (('"    << endl;
    cout << "       ))                                                          "       << endl; cout << endl;
    cout << "                        by TwoHeadedShark                          "       << endl; cout << endl;

    // menu switch statement

    bool menu = false;

    int menuChoice = 0;
    int menuChoice2 = 0;

    do {
        cout << "1) Start New Game" << endl;
        cout << "2) Load Previous Game" << endl;
        cout << "Enter choice [1, 2]: " << endl;
        cin >> menuChoice;

        switch (menuChoice) {

            case 1:                         /* if menuChoice == 1 */
                if (lineCount != 0) {       /* if file is NOT empty */
                    cout << endl; cout << "This will erase previous game progress. Continue? [3 = Yes, 4 = No]" << endl;
                    cin >> menuChoice2;
                    if (menuChoice2 == 3) { /* yes, continue */
                        cout << endl; cout << "Erasing game data..." << endl; cout << endl;
                        menu = true;
                        
                        ifstream finDelete(FILENAME);                                   /* delets content in file */
                        ofstream foutDelete;
                        foutDelete.open(FILENAME, ofstream::out | ofstream::trunc);
                        finDelete.close();
                        foutDelete.close();

                        ofstream fout_1(FILENAME, _S_app);                              /* append "s" to file */
                        fout_1 << "s" << endl;
                        fout_1.close();

                        lineCount = 0;
                        lineCount++;
                        break;
                    }

                    else if (menuChoice2 == 4) { /* no, exit */
                        cout << endl; cout << "Returning to main menu..." << endl; cout << endl;
                        break;
                    }

                    else {                  /* not 3 or 4 */
                        cout << endl; cout << "Invalid option, try again!" << endl; cout << endl;
                        break;
                    }
                }

                else if (lineCount == 0) {  /* if file is empty */
                    cout << endl; cout << "Starting new game!" << endl; cout << endl;   
                    menu = true;            /* ends menu switch statement */

                    ofstream fout_2(FILENAME, _S_app);                              /* append "s" to file */
                    fout_2 << "s" << endl;
                    fout_2.close();

                    lineCount++;
                    break;                  /* skips to while () */
                }
            
            
            case 2:                         /* if menuChoice == 2 */
                if (lineCount == 0) {       /* if file is empty */
                    cout << endl; cout << "Saved game data not found!" << endl; cout << endl;
                    break;
                }

                else if (lineCount != 0) {  /* if file is NOT empty */
                    cout << endl; cout << "Loading saved game..." << endl; cout << endl;
                    menu = true;            /* ends menu switch statement */
                    break;                  /* skips to while () */
                }


            default:
                cout << endl; cout << "Invalid option, try again!" << endl; cout << endl;
                break;
        }
    } while (!menu);                        /* while menu != true, restart do {} */

    // userName

    string userName;
    int i = 0;

    ifstream fin2(FILENAME);                 /* read from file 2 */
    ofstream fout2(FILENAME, _S_app);        /* append to file 2 */

    if (lineCount > 1) {
        while (getline(fin2, line)) {
            if (i == 1) {
                userName = line;
            }
            i++;
        }
        cout << "Welcome back, Captain " << userName << "!" << endl; cout << endl;
    }

    else if (lineCount == 1) {
        cout << "Enter your name: " << endl; cin >> userName;
        cout << "Howdy, Captain " << userName << "!" << endl; cout << endl;
        fout2 << userName << endl;
        lineCount++;
    }

    else {
        cout << "You getting this error should not be possible..." << endl;
    }

    fin2.close();
    fout2.close();

    // random spawn

    if (lineCount == 2) {
        Submarine();
    }

    // if lineCount == 2 (s + userName)
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
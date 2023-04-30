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

    fout << "s" << endl;                // DELETE ME !!!!!
    fout << "Jack Sparrow" << endl;     // DELETE ME !!!!!!!!!!!
    fout << "7" << endl;                // DELETE ME !!!!!!!!
    fout << "12" << endl;               // DELETE ME
    fout << "15" << endl;               // DELETE ME

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

    ifstream fin2(FILENAME);                /* read from file 2 */
    ofstream fout2(FILENAME, _S_app);       /* append to file 2 */

    if (lineCount > 1) {                    /* if file has more lines than 1 ("s") */
        while (getline(fin2, line)) {
            if (i == 1) {
                userName = line;
            }
            i++;
        }
        cout << "Welcome back, Captain " << userName << "!" << endl; cout << endl;
    }

    else if (lineCount == 1) {              /* if file has only one line ("s") */
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

    ifstream fin3(FILENAME);                 /* read from file 3 */
    ofstream fout3(FILENAME, _S_app);        /* append to file 3 */
    i = 0;                                   /* start counting from 0 */

    //cout << "LINECOUNT:" << lineCount << endl;                                              // DELETE ME !!!!!!

    Submarine playerSub;

    if (lineCount == 2) {
        cout << "Randomizing submarine stats..." << endl; cout << endl;
        playerSub = Submarine();

        cout << "Fuel Amount: " << playerSub.getFuel() << "/" << playerSub.getFuelCap() << endl;
        cout << "Air Amount: " << playerSub.getAir() << "/" << playerSub.getAirCap() << endl;
        cout << "Crew Amount: " << playerSub.getCrew() << "/" << playerSub.getCrewCap() << endl;

        cout << endl; cout << "Game ends if any of these stats reach 0!" << endl; cout << endl;
    }

    else if (lineCount > 2) {
        cout << "Gathering saved submarine stats..." << endl; cout << endl;
        string fS; string aS; string cS;
        int f; int a; int c;
        while (getline(fin3, line)) {   // TODO: GATHER TURN STATS TO INT AND CREATE SUBMARINE OBJECT W STATS FROM FILE
            if (i == 2) {                       /* fuel is on line 3 */
                //f = line;
            }

            else if (i == 3) {                  /* air is on line 4 */
                //a = line;
            }

            else if (i == 4) {                  /* crew is on line 5 */
                //c = line;
            }

            i++;
        } 

        //playerSub = Submarine(f, a, c);

        cout << "Fuel Amount: " << playerSub.getFuel() << "/" << playerSub.getFuelCap() << endl;
        cout << "Air Amount: " << playerSub.getAir() << "/" << playerSub.getAirCap() << endl;
        cout << "Crew Amount: " << playerSub.getCrew() << "/" << playerSub.getCrewCap() << endl;

        cout << "Remember not to let these stats reach 0!" << endl; cout << endl;
    }

    fin3.close();
    fout3.close();

    return 0;
}
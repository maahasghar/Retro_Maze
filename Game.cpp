/**< This main program was created by Maah Asghar and Syeda Nehal Hussain
This main program will:
Read a map for the maze and draw it into a window
Create two characters that can play in the maze:
Player one (â€œDonkeyâ€) will be able to traverse on a map.So that they can reach the end of the maze.
Player two (â€œShrekâ€) will be able to traverse on a map. So that they can catch the other player.
Date: Thu Nov 28 2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <unistd.h> /* close */
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <ncurses.h> // for moving
#include <termios.h>
#include <unistd.h>
#include <stdio.h>




static struct termios old, newp;
void displayMap();
void donkeyAction();
void shrekAction();
void initTermios(int echo);
void resetTermios(void);
char getch_(int echo);
char getch1(void);


using namespace std;

const int WIDTH = 98;
const int HEIGHT = 29;
unsigned char playerDonkey;
unsigned char playerShrek;
int posX_donkey;
int posY_donkey;
int posX_shrek;
int posY_shrek;

unsigned char action;
unsigned char moves;

unsigned char maze[HEIGHT][WIDTH];

/**
 * The main function will read a file that has a map stored in it,
 * then read the map for the maze and draw it into a window
 */
int main(){
    unsigned char donkeyIcon;
    unsigned char shrekIcon;
    // cout << "\x1b[1;35m" << std::endl;
   // cout << "\x1b[1;34m" <<
    

    cout << "\x1b[1;34m" << "         ___         " << "\x1b[1;31m" << "  ___      " << "\x1b[1;33m" << "     ___       " << "\x1b[1;32m" << "    ___ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "        /\\  \\      " << "\x1b[1;31m" << "   /\\  \\     " << "\x1b[1;33m" << "    /\\__\\     " << "\x1b[1;32m" << "    /\\__\\ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "       |::\\  \\     " << "\x1b[1;31m" << "  /::\\  \\    " << "\x1b[1;33m" << "   /::|  |    " << "\x1b[1;32m" << "   /:/ _/_ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "       |:|:\\  \\    " << "\x1b[1;31m" << " /:/\\:\\  \\    " << "\x1b[1;33m" << " /:/:|  |    " << "\x1b[1;32m" << "  /:/ /\\__\\ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "     __|:|\\:\\  \\  " << "\x1b[1;31m" << " /:/ /::\\  \\  " << "\x1b[1;33m" << " /:/|:|  |__  " << "\x1b[1;32m" << " /:/ /:/ _/_ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "    /::::|_\\:\\__\\ " << "\x1b[1;31m" << "/:/_/:/\\:\\__\\ " << "\x1b[1;33m" << "/:/ |:| /\\__\\ " << "\x1b[1;32m" << "/:/_/:/ /\\__\\ " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "    \\:\\__\\  \\/__/" << "\x1b[1;31m" << " \\:\\/:/  \\/__/ " << "\x1b[1;33m" << "\\/__|:|/:/  / " << "\x1b[1;32m" << "\\:\\/:/ /:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "     \\:\\  \\       " << "\x1b[1;31m" << " \\::/__/      " << "\x1b[1;33m" << "    |:/:/  /  " << "\x1b[1;32m" << " \\::/_/:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "      \\:\\  \\      " << "\x1b[1;31m" << "  \\:\\  \\      " << "\x1b[1;33m" << "    |::/  /   " << "\x1b[1;32m" << "  \\:\\/:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "       \\:\\__\\     " << "\x1b[1;31m" << "   \\:\\__\\     " << "\x1b[1;33m" << "    |:/  /    " << "\x1b[1;32m" << "   \\::/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;34m" << "        \\/__/       " << "\x1b[1;31m" << "  \\/__/     " << "\x1b[1;33m" << "    |/__/    " << "\x1b[1;32m" << "     \\/__/ " << "\x1b[0m " << endl;


    cout << "\x1b[1;32m" << "         ___        " << "\x1b[1;33m" << "   ___ " << "\x1b[1;31m" << "           ___      " << "\x1b[1;34m" << "     ___ " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "        /\\__\\     " << "\x1b[1;33m" << "    /\\  \\ " << "\x1b[1;31m" << "         /\\  \\    " << "\x1b[1;34m" << "     /\\__\\ " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "       /:/ _/_      " << "\x1b[1;33m" << " /::\\  \\" << "\x1b[1;31m" << "        |::\\  \\   " << "\x1b[1;34m" << "    /:/ _/_ " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "      /:/ /\\  \\   " << "\x1b[1;33m" << "  /:/\\:\\  \\" << "\x1b[1;31m" << "       |:|:\\  \\   " << "\x1b[1;34m" << "  /:/ /\\__\\ " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "     /:/ /::\\  \\  " << "\x1b[1;33m" << " /:/ /::\\  \\" << "\x1b[1;31m" << "    __|:|\\:\\  \\  " << "\x1b[1;34m" << " /:/ /:/ _/_ " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "    /:/__\\/\\:\\__\\" << "\x1b[1;33m" << " /:/_/:/\\:\\__\\" << "\x1b[1;31m" << " /::::|_ \\:\\__\\ " << "\x1b[1;34m" << "/:/_/:/ /\\__\\" << "\x1b[0m " << endl;;
    cout << "\x1b[1;32m" << "    \\:\\  \\ /:/  /" << "\x1b[1;33m" << " \\:\\/:/  \\/__/" << "\x1b[1;31m" << " \\:\\__\\   \\/__/ " << "\x1b[1;34m" << "\\:\\/:/ /:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "     \\:\\  /:/  /  " << "\x1b[1;33m" << " \\::/__/" << "\x1b[1;31m" << "       \\:\\  \\    " << "\x1b[1;34m" << "     \\::/_/:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "      \\:\\/:/  /   " << "\x1b[1;33m" << "  \\:\\  \\" << "\x1b[1;31m" << "        \\:\\  \\   " << "\x1b[1;34m" << "      \\:\\/:/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "       \\::/  /     " << "\x1b[1;33m" << "  \\:\\__\\" << "\x1b[1;31m" << "        \\:\\__\\   " << "\x1b[1;34m" << "      \\::/  / " << "\x1b[0m " << endl;
    cout << "\x1b[1;32m" << "        \\/__/      " << "\x1b[1;33m" << "   \\/__/" << "\x1b[1;31m" << "         \\/__/     " << "\x1b[1;34m" << "     \\/__/ " << "\x1b[0m " << endl;

    cout << "\x1b[0m \n" << std::endl;
    cout << "Press enter to continue...";
    cin.get(); //Pause Command for Linux Terminal
    system("clear");
    //Randdom file reader
    std::ifstream inFile;
    std::string lineRead, firstLine, secondLine;

    /*************************************************************
    *                     RANDOM FILE GENERATOR                  *
    *************************************************************/

    int code = 0;
    string input;
    cout << "Pick a level of the game \n";
    cout << "E: Easy " << endl;
    cout << "M: Medium " << endl;
    cout << "H: Hard " << endl;
    cin >> input;
    cout << endl;
    if (input == "E" || input == "e")
    {
        srand(time(NULL));
        code = rand() % 3;
        //std::cout << "Random File Code ";
        //cout << to_string(code);
        //cout << "\n";
    }
    else if (input == "M" || input == "m") {
        srand(time(NULL));
        code = rand() % 6;
        while (!(code > 5)) {
            code = rand() % 6;
        }
        //std::cout << "Random File Code ";
        //cout << to_string(code);
        //cout << "\n";
    }
    else if (input == "H" || input == "h") {
        srand(time(NULL));
        code = rand() % 9;
        while (!(code > 8)) {
            code = rand() % 9;
        }
       // std::cout << "Random File Code ";
        //cout << to_string(code);
        //cout << "\n";
    }

    string filename = "Test" + to_string(code) + ".txt";
    cout << "filename: " + filename << std::endl;
    

    inFile.open("Test8.txt"); //open file
    if (!inFile) cout << "Failed to load level" << std::endl;
    else {
        int i = 0;
        std::getline(inFile, firstLine);
        std::getline(inFile, secondLine);
        string str = firstLine.substr(0, 2);
        posY_donkey = stoi(str);
        string str1 = firstLine.substr(3, 4);
        posX_donkey = stoi(str1); //shouldnt be same position as shrek
        string str2 = secondLine.substr(0, 2);
        posY_shrek = stoi(str2);
        string str3 = secondLine.substr(3, 5);
        posX_shrek = stoi(str3); //shouldnt be same position as shrek
        for (int y = 0; y < HEIGHT && !inFile.eof(); y++) {
            std::getline(inFile, lineRead); ///get each line from text file
            for (int x = 0; x < WIDTH && !inFile.eof(); x++) {
                maze[y][x] = lineRead[i]; ///< print line to form the maze
                i++;
            }
            i = 0;
        }
    }
    //###########################################################################################


// basic instructions
    cout << "                       \x1b[1;33;1;41m_____________________________________\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|    Hellooo, my names donkey!      |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|  Shrek and I are going to play a  |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|  game... and I need your help!    |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|                                   |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|It's simple, I just need to get to |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m| the end of the maze before shrek  |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m|              catches me           |\x1b[0m" << endl;
    cout << "                       \x1b[1;33;1;41m-------------------------------------\x1b[0m" << endl;
    cout << "\x1b[1;34m                          ^__^ \x1b[1;33m/ \x1b[0m" << endl;
    cout << "\x1b[1;34m                  _______/(@@)\x1b[1;33m/ \x1b[0m" << endl;
    cout << "\x1b[1;34m                /(       /(__) " << endl;
    cout << "\x1b[1;34m               ^ |-----||" << endl;
    cout << "\x1b[1;34m                 ||    ||" << endl;
    cout << "\x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\x1b[0m" << endl;
    cout << "\x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "\x1b[0m \n" << std::endl;

    cout << "Press enter to continue...\n" << std::endl;
    cin.get(); //Pause Command for Linux Terminal
    system("clear");

    cout << "              \x1b[1;33;1;41m_____________________________________\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m|    The end of the maze looks      |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m|        like this --> 'E'          |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m|                                   |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m| Control me by using WASD keys     |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m| Control sherk by using IJKL keys  |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m|                                   |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m|          To quit press q          |\x1b[0m" << endl;
    cout << "              \x1b[1;33;1;41m-------------------------------------\x1b[0m" << endl;
    cout << "\x1b[1;33m                                       \\\x1b[1;34m  ^__^           " << endl;
    cout << "\x1b[1;33m                                        \\\x1b[1;34m (@@)\\_______" << endl;
    cout << "\x1b[1;34m                                          (__)\\       )\\" << endl;
    cout << "\x1b[1;34m                                               ||-----| ^" << endl;
    cout << " \x1b[1;34m                                              ||    ||" << endl;
    cout << " \x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\x1b[0m" << endl;
    cout << " \x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "\x1b[0m \n" << std::endl;


    cout << "Press enter to continue...\n" << std::endl;
    cin.get(); //Pause Command for Linux Terminal
    system("clear");


    cout << "            \x1b[1;33;1;41m_________________________________\x1b[0m" << endl;
    cout << "            \x1b[1;33;1;41m|   Player 1 lets pick my avatar|\x1b[0m" << std::endl;
    cout << "            \x1b[1;33;1;41m|    Here are your options:     |\x1b[0m" << std::endl;
    cout << "            \x1b[1;33;1;41m|       Enter 1 - @             |\x1b[0m" << endl;
    cout << "            \x1b[1;33;1;41m|       Enter 2 - &             |\x1b[0m" << endl;
    cout << "            \x1b[1;33;1;41m|       Enter 3 - O             |\x1b[0m" << endl;
    cout << "            \x1b[1;33;1;41m---------------------------------\x1b[0m" << endl;
    cout << "\x1b[1;34m                          ^__^ \x1b[1;33m/ \x1b[0m" << endl;
    cout << "\x1b[1;34m                  _______/(@@)\x1b[1;33m/ \x1b[0m" << endl;
    cout << "\x1b[1;34m                /(       /(__) " << endl;
    cout << "\x1b[1;34m               ^ |-----||" << endl;
    cout << "\x1b[1;34m                 ||    ||" << endl;
    cout << "   \x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\x1b[0m" << endl;
    cout << "   \x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "\x1b[0m \n" << std::endl;

    cout << "o()xxxx[{:::::::::> SELECT:";
    cin >> donkeyIcon;
    switch (donkeyIcon) {
    case'1':
        playerDonkey = '@';
        break;
    case'2':
        playerDonkey = '&';
        break;
    case'3':
        playerDonkey = 'O';
        break;
    case 'q'://player one can quit the game
        cout << "GAME ENDED!" << endl;
        exit(0);
        break;

    default: //else incorrect input
        break;
    }
    system("clear");


    cout << "             \x1b[1;33;1;41m__________________________________\x1b[0m" << endl;
    cout << "             \x1b[1;33;1;41m|Player 2 lets pick shreks avatar|\x1b[0m" << std::endl;
    cout << "             \x1b[1;33;1;41m|    Here are your options:      |\x1b[0m" << std::endl;
    cout << "             \x1b[1;33;1;41m|          Enter 1 - $           |\x1b[0m" << endl;
    cout << "             \x1b[1;33;1;41m|          Enter 2 - #           |\x1b[0m" << endl;
    cout << "             \x1b[1;33;1;41m|          Enter 3 - X           |\x1b[0m" << endl;
    cout << "             \x1b[1;33;1;41m---------------------------------|\x1b[0m" << endl;
    cout << "\x1b[1;33m                                        \\\x1b[1;34m    ^__^           " << endl;
    cout << "\x1b[1;33m                                         \\\x1b[1;34m   (@@)\\_______" << endl;
    cout << "\x1b[1;34m                                             (__)\\        )\\" << endl;
    cout << "\x1b[1;34m                                                  ||-----| ^" << endl;
    cout << "\x1b[1;34m                                                  ||    ||" << endl;
    cout << "\x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\x1b[0m" << endl;
    cout << "\x1b[1;32;1;42mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "\x1b[0m \n" << std::endl;

    cout << "o()xxxx[{:::::::::> SELECT:";
    cin >> shrekIcon;
    switch (shrekIcon) {
    case'1':
        playerShrek = '$';
        break;
    case'2':
        playerShrek = '#';
        break;
    case'3':
        playerShrek = 'X';
        break;
    case 'q'://player one can quit the game
        cout << "Game ended!" << endl;
        exit(0);
        break;

    default: //else incorrect input
        break;
    }
    cout << "Press enter to continue...\n" << std::endl;
    cin.get(); //Pause Command for Linux Terminal
    system("clear");

    displayMap(); // calls display function
    while (action != 'q' || action != 'Q') {
        // call all the functionss
        donkeyAction();
        shrekAction();
        displayMap();
    }
    return 0;

}

/** This function will display basic instructions on how to move characters,
 * will display the maze that was stored in the 2d array,
 * and will place characters into the maze
 */
void displayMap() {

    char printChar = '\0';
    // characters into the maze
    maze[posX_donkey][posY_donkey] = playerDonkey;
    maze[posX_shrek][posY_shrek] = playerShrek;

    // runs the 2D array
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printChar = maze[y][x];
            std::cout << "\x1b[1;33;46m" << printChar << "\x1b[0m"; //draw the maze
        }
        std::cout << endl;

    }
    endwin();

}

/** This function will let player one move around the map so that it can reach the end of the maze.
 */
void donkeyAction() {
    // ask user where they want to move
    action = getch1();

    int prevposX = posX_donkey;
    int prevposY = posY_donkey;
    unsigned char space = { 32 };

    switch (action) {
    case'a': // going left
            // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_donkey][posY_donkey - 1] != '+' && maze[posX_donkey][posY_donkey - 1] != '-' && maze[posX_donkey][posY_donkey - 1] != '|') {
            // the character tries to move but accidentlly moves into shrek, the game will end and shrek wins
            if (maze[posX_donkey][posY_donkey - 1] == playerShrek) {
                cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            // the character reaches the exit the game will end and donkey wins
            if (maze[posX_donkey][posY_donkey - 1] == 'E') {
                cout << "\x1b[1;34m" << endl;
                    cout << "     _                  _                     _             " << endl;
                    cout << "    | |                | |                   (_)           " << endl;
                    cout << "  __| | ___  _ __   ___| | ___   _  __      ___ _ __  ___  " << endl;
                    cout << " / _` |/ _ \\| '_ \\ / _ \\ |/ / | | | \\ \\ /\\ / / | '_ \\/ __| " << endl;
                    cout << "| (_| | (_) | | | |  __/   <| |_| |  \\ V  V /| | | | \\__ \\ " << endl;
                    cout << " \\__,_|\\___/|_| |_|\\___|_|\\_ \\__, |   \\_/\\_/ |_|_| |_|___/ " << endl;
                     cout << "                             __/ |                       " << endl;
                      cout << "                            |___/                        " << endl;
                cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posY_donkey = posY_donkey - 1;
            maze[prevposX][prevposY] = space;  // convert back into prev space
        }

        break;

    case'd': // going right
         // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_donkey][posY_donkey + 1] != '+' && maze[posX_donkey][posY_donkey + 1] != '-' && maze[posX_donkey][posY_donkey + 1] != '|') {
            // the character tries to move but accidentlly moves into shrek, the game will end and shrek wins
            if (maze[posX_donkey][posY_donkey + 1] == playerShrek) {
                cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            // the character reaches the exit the game will end and donkey wins
            if (maze[posX_donkey][posY_donkey + 1] == 'E') {
               cout << "\x1b[1;34m" << endl;
                    cout << "     _                  _                     _             " << endl;
                    cout << "    | |                | |                   (_)           " << endl;
                    cout << "  __| | ___  _ __   ___| | ___   _  __      ___ _ __  ___  " << endl;
                    cout << " / _` |/ _ \\| '_ \\ / _ \\ |/ / | | | \\ \\ /\\ / / | '_ \\/ __| " << endl;
                    cout << "| (_| | (_) | | | |  __/   <| |_| |  \\ V  V /| | | | \\__ \\ " << endl;
                    cout << " \\__,_|\\___/|_| |_|\\___|_|\\_ \\__, |   \\_/\\_/ |_|_| |_|___/ " << endl;
                     cout << "                             __/ |                       " << endl;
                      cout << "                            |___/                        " << endl;
                cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posY_donkey = posY_donkey + 1;
            maze[prevposX][prevposY] = space; // convert back into prev space
        }

        break;

    case's': //going down
            // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_donkey + 1][posY_donkey] != '+' && maze[posX_donkey + 1][posY_donkey] != '-' && maze[posX_donkey + 1][posY_donkey] != '|') {
            // the character tries to move but accidentlly moves into shrek, the game will end and shrek wins
            if (maze[posX_donkey + 1][posY_donkey] == playerShrek) {
                  cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            // the character reaches the exit the game will end and donkey wins
            if (maze[posX_donkey + 1][posY_donkey] == 'E') {
                cout << "\x1b[1;34m" << endl;
                    cout << "     _                  _                     _             " << endl;
                    cout << "    | |                | |                   (_)           " << endl;
                    cout << "  __| | ___  _ __   ___| | ___   _  __      ___ _ __  ___  " << endl;
                    cout << " / _` |/ _ \\| '_ \\ / _ \\ |/ / | | | \\ \\ /\\ / / | '_ \\/ __| " << endl;
                    cout << "| (_| | (_) | | | |  __/   <| |_| |  \\ V  V /| | | | \\__ \\ " << endl;
                    cout << " \\__,_|\\___/|_| |_|\\___|_|\\_ \\__, |   \\_/\\_/ |_|_| |_|___/ " << endl;
                     cout << "                             __/ |                       " << endl;
                      cout << "                            |___/                        " << endl;
                cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posX_donkey = posX_donkey + 1;
            maze[prevposX][prevposY] = space;  // convert back into prev space
        }
        break;

    case'w': //going up
             // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_donkey - 1][posY_donkey] != '+' && maze[posX_donkey - 1][posY_donkey] != '-' && maze[posX_donkey - 1][posY_donkey] != '|') {
            // the character tries to move but accidentlly moves into shrek, the game will end and shrek wins
            if (maze[posX_donkey - 1][posY_donkey] == playerShrek) {
                  cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            // the character reaches the exit the game will end and donkey wins
            if (maze[posX_donkey - 1][posY_donkey] == 'E') {
                cout << "\x1b[1;34m" << endl;
                    cout << "     _                  _                     _             " << endl;
                    cout << "    | |                | |                   (_)           " << endl;
                    cout << "  __| | ___  _ __   ___| | ___   _  __      ___ _ __  ___  " << endl;
                    cout << " / _` |/ _ \\| '_ \\ / _ \\ |/ / | | | \\ \\ /\\ / / | '_ \\/ __| " << endl;
                    cout << "| (_| | (_) | | | |  __/   <| |_| |  \\ V  V /| | | | \\__ \\ " << endl;
                    cout << " \\__,_|\\___/|_| |_|\\___|_|\\_ \\__, |   \\_/\\_/ |_|_| |_|___/ " << endl;
                     cout << "                             __/ |                       " << endl;
                      cout << "                            |___/                        " << endl;
                cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posX_donkey = posX_donkey - 1;
            maze[prevposX][prevposY] = space; //convert back into prev space
        }
        break;

    case 'q':// player one can quit the game
        cout << "Game ended!" << endl;
        exit(0);
        break;

    default: // else incorrect input
        break;
    }


}


/**
 * This function will let player two move around on the ma,
 * so that they can catch the other player before they exit the maze
 */
void shrekAction() {


    moves = getch1(); //reading a char without echo


    int prevposX = posX_shrek;
    int prevposY = posY_shrek;
    unsigned char space = { 32 };

    switch (moves) {
    case 'j': //going left
        // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_shrek][posY_shrek - 1] != '+' && maze[posX_shrek][posY_shrek - 1] != 'E' && maze[posX_shrek][posY_shrek - 1] != '-' && maze[posX_shrek][posY_shrek - 1] != '|') {
            //  the character moves and chatches other player, the game will end and shrek wins
            if (maze[posX_shrek][posY_shrek - 1] == playerDonkey) {
                   cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;

                exit(0);
            }
            posY_shrek = posY_shrek - 1;
            maze[prevposX][prevposY] = space; // convert back into prev space
        }
        refresh();
        system("clear");
        break;

    case 'l': //going right
            // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_shrek][posY_shrek + 1] != '+' && maze[posX_shrek][posY_shrek + 1] != 'E' && maze[posX_shrek][posY_shrek + 1] != '-' && maze[posX_shrek][posY_shrek + 1] != '|') {
            // the character moves and chatches other player, the game will end and shrek wins
            if (maze[posX_shrek][posY_shrek + 1] == playerDonkey) {
                   cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;

                exit(0);
            }
            posY_shrek = posY_shrek + 1;
            maze[prevposX][prevposY] = space;
        }
        refresh(); // refreshes the page
        system("clear");
        break;

    case 'k': // going down
             // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_shrek + 1][posY_shrek] != '+' && maze[posX_shrek][posY_shrek + 1] != 'E' && maze[posX_shrek + 1][posY_shrek] != '-' && maze[posX_shrek + 1][posY_shrek] != '|') {
            // the character moves and chatches other player, the game will end and shrek wins
            if (maze[posX_shrek + 1][posY_shrek] == playerDonkey) {
                   cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posX_shrek = posX_shrek + 1;
            maze[prevposX][prevposY] = space; // convert back into prev space
        }
        refresh();
        system("clear"); // clear screen
        break;

    case 'i': // going up
              // if the character moves but there is a wall it will fail else it will move
        if (maze[posX_shrek - 1][posY_shrek] != '+' && maze[posX_shrek][posY_shrek + 1] != 'E' && maze[posX_shrek - 1][posY_shrek] != '-' && maze[posX_shrek - 1][posY_shrek] != '|') {
            // the character moves and chatches other player, the game will end and shrek wins
            if (maze[posX_shrek - 1][posY_shrek] == playerDonkey) {
                   cout << "\x1b[1;32m" << endl;
                     cout << "     _              _               _           " << endl;
                     cout << "    | |            | |             (_)          " << endl;
                     cout << " ___| |__  _ __ ___| | __ __      ___ _ __  ___ " << endl;
                     cout << "/ __| '_ \\| '__/ _ \\ |/ / \\ \\ /\\ / / | '_ \\/ __|" << endl;
                     cout << "\\__ \\ | | | | |  __/   <   \\ V  V /| | | | \\__ \\ " << endl;
                     cout << "|___/_| |_|_|  \\___|_|\\_\\   \\_/\\_/ |_|_| |_|___/" << endl;
                     cout << "\x1b[0m \n" << endl;
                exit(0);
            }
            posX_shrek = posX_shrek - 1;
            maze[prevposX][prevposY] = space; // convert back into prev space
        }
        refresh();
        system("clear");
        break;

    case 'q':// player two can quit the game
        cout << "Game ended!" << endl;
        refresh();
        exit(0);
        break;

    default: // else not vaild input
        refresh();
        system("clear");
        break;
    }


}

/*****************************************************************
*                          DISPLAY                               *
******************************************************************/

/** This function initializes new terminal i/o settings.
 */
void initTermios(int echo)
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    newp = old; // make new settings same as old settings
    newp.c_lflag &= ~ICANON; // disable buffered i/o
    newp.c_lflag &= echo ? ECHO : ~ECHO; // set echo mode
    tcsetattr(0, TCSANOW, &newp); /* use these new terminal i/o settings now */
}


/** Restore old terminal i/o settings
 */
void resetTermios(void)
{
    tcsetattr(0, TCSANOW, &old);
}

/** This function reads 1 character - echo defines echo mode.
 */
char getch_(int echo)
{
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}

/** Read 1 character without echo
 */
char getch1(void) {
    return getch_(0);
}




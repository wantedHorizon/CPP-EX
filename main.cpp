#include "Board.h"

#include <iostream>
using namespace std;

int main() {
    Board board1{4};  // Initializes a 4x4 board
    cout << board1 << endl;   /* Shows an empty board:
	....
	....
	....
	....
	*/
    cout << board1[{1,2}] << endl; // .
    board1[{1,1}]='X';
    board1[{1,2}]='O';

    Board board2 = board1;

    board2[{0,0}] = 'X';
  bool x=(board1==board2);

    cout << (board1!=board2)<<"true"<< endl;  /* Shows an empty board, as above */
    cout << board2 << endl;  /* Shows a board with an X at top-left */

    board1 = board2;
    board1[{3,3}] = 'O';
    cout << board2 << endl;  /* Shows a board with an X at top-left */
    cout << board1 << endl;  /* Shows a board with an X at top-left and O at bottom-right */

    cout << "Good bye!" << endl;

    return 0;
}

#ifndef CONNECTFOURBOARD_H_INCLUDED
#define CONNECTFOURBOARD_H_INCLUDED

/* used to create an abstract data type
   Move which contains 2 fields one for row index
   and the other for column index*/
struct Move {
    int row_index;
    int col_index;
};

class connectFourBoard {
   public:
    /*this pointer to a pointer variable is used to dynamically create
     a 2-d array for the connect-four board and the dimensions
     are rows-6, and columns-7
    */
    char **board;
    // this is used for row size of the board and is set to 6
    int row_size;
    // this is used for col size of the board and is set to 7
    int col_size;
    // this is used to know who the player is at that particular board
    char player;
    // this is used to dynamically create an moves array using concept
    Move *moves;

    // Member functions of this class
    connectFourBoard();
    bool isBoardEmpty();
    int makeFirstMove();
    void checkPossibleMoves();
    bool checkPlayerWon();
    void operator=(connectFourBoard);
    void display_board(connectFourBoard *x);
};
#endif  // CONNECTFOURBOARD_H_INCLUDED

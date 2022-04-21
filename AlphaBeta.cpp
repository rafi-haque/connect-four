#include "AlphaBeta.h"

#include <iostream>

#include "ConnectFourBoard.h"
#include "TreeNodes.h"
using namespace std;

// constructor
alphabeta::alphabeta() {
    eval_choice = ' ';
}

/* this function is implemented from the algorithm given
   in Russell & Norvig text book.
   this function is used to find the node which is more probable to win
   in the future if the player plays the move returned by this function.

   in this function there are 3 cases 1st being base case , 2nd being recursive case
   for player 'X' i.e Max player and the 3rd being recursive case for player 'Y'
   i.e Min player

*/
int alphabeta::alpha_beta(tree* tob, int depth, char player, int alpha, int beta) {
    // gets executed if eval 1 is selected by user
    if (eval_choice == '1') {
        if (tob->deep_enough(depth))
            return tob->evaluation1();
    }

    // gets executed if eval 2 is chosen
    else if (eval_choice == '2') {
        if (tob->deep_enough(depth))
            return tob->evaluation2();
    }

    // gets executed if eval 3 is used
    else if (eval_choice == '3') {
        if (tob->deep_enough(depth))
            return tob->evaluation3();
    }

    if (player == 'X') {
        int best_value = -100, value;
        for (int i = 0; i < 7; i++) {
            if (tob->children[i] == NULL)
                continue;
            value = alpha_beta(tob->children[i], depth + 1, player, alpha, beta);
            best_value = (best_value > value) ? best_value : value;
            alpha = (alpha > best_value) ? alpha : best_value;

            if (beta <= alpha)
                break;
        }
        tob->set_heuristic_value(best_value);
        return best_value;
    }

    else {
        int best_value = +100, value;
        for (int i = 0; i < 7; i++) {
            if (tob->children[i] == NULL)
                continue;
            value = alpha_beta(tob->children[i], depth + 1, player, alpha, beta);
            best_value = (best_value < value) ? best_value : value;
            beta = (beta < best_value) ? beta : best_value;

            if (beta < alpha)
                break;
        }
        tob->set_heuristic_value(best_value);
        return best_value;
    }
}

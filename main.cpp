#include <ctime>
#include <iostream>

#include "AlphaBeta.h"
#include "ConnectFourBoard.h"
#include "MinmaxAB.h"
#include "TreeNodes.h"
using namespace std;

int num_nodes_generated, num_nodes_expanded, game_path_length, start_time, stop_time;

char evalfn_choiceX, evalfn_choiceO;

/* creates a tree object,board object and minmaxab object
   using a while loop keeps calling the minmaxAB function
   repeatedly until the condition checkPlayerWon evaluates
   to true. */
void MinMax() {
    int moves_made = 0;
    connectFourBoard *board_object = new connectFourBoard;

    cout << endl;

    board_object->display_board(board_object);
    board_object->player = 'X';

    start_time = clock();
    while (!board_object->checkPlayerWon()) {
        tree *head = new tree;
        *(head->ob) = *board_object;

        if (head->ob->isBoardEmpty()) {
            int random_col_index = head->ob->makeFirstMove();
            head->ob->board[0][random_col_index] = 'X';
            head->ob->player = 'X';
            moves_made++;
            game_path_length++;
        }

        minmaxA minmax_object;
        // assigns the users choice of evaluation function chosen
        minmax_object.eval_choice = evalfn_choiceX;
        int x = minmax_object.minmaxAB(head, 0, 1000, -1000, head->ob->player);
        moves_made++;
        game_path_length++;

        // to get the optimal node - Move Gen function
        head->generate_move(board_object, moves_made);
    }
    stop_time = clock();
}

/* for calling minmaxAB function
   creates a tree object,board object and alphabeta object
   using a while loop keeps calling the alphabeta function
   repeatedly until the condition checkPlayerWon evaluates
   to true. */
void AlphaBeta() {
    int moves_made = 0;

    connectFourBoard *board_object = new connectFourBoard;

    cout << endl;

    board_object->display_board(board_object);
    board_object->player = 'X';

    start_time = clock();
    while (!board_object->checkPlayerWon()) {
        tree *head = new tree;
        *(head->ob) = *board_object;

        if (head->ob->isBoardEmpty()) {
            int random_col_index = head->ob->makeFirstMove();
            head->ob->board[0][random_col_index] = 'X';
            head->ob->player = 'X';
            moves_made++;
            game_path_length++;
        }

        alphabeta alphaBeta_object;
        // assigns the users choice of evaluation function chosen
        alphaBeta_object.eval_choice = evalfn_choiceO;
        int x = alphaBeta_object.alpha_beta(head, 0, head->ob->player, 1000, -1000);
        moves_made++;
        game_path_length++;

        // to get the optimal node - Move Gen function
        head->generate_move(board_object, moves_made);
    }
    stop_time = clock();
}

int main() {
    int algo_choiceX, algo_choiceO;
    cout << "X will use : " << endl;
    cout << endl;
    cout << "  1 - MinmaxAB" << endl;
    cout << "  2 - AlphaBeta" << endl;
    cout << endl;
    cin >> algo_choiceX;
    cout << endl;

    cout << "O will use : " << endl;
    cout << endl;
    cout << "  1 - MinmaxAB" << endl;
    cout << "  2 - AlphaBeta" << endl;
    cout << endl;
    cin >> algo_choiceO;
    cout << endl;

    cout << "Player X - evaluation function : " << endl;
    cout << "  1 - evaluation function 1" << endl;
    cout << "  2 - evaluation function 2" << endl;
    cout << "  3 - evaluation function 3" << endl;
    cout << endl;
    cin >> evalfn_choiceX;
    cout << endl;

    cout << "Player X - evaluation function : " << endl;
    cout << "  1 - evaluation function 1" << endl;
    cout << "  2 - evaluation function 2" << endl;
    cout << "  3 - evaluation function 3" << endl;
    cout << endl;
    cin >> evalfn_choiceO;
    cout << endl;

    int moves_made = 0;
    connectFourBoard *board_object = new connectFourBoard;

    cout << endl;

    board_object->player = 'X';

    start_time = clock();
    while (!board_object->checkPlayerWon()) {
        tree *head = new tree;
        *(head->ob) = *board_object;

        if (head->ob->isBoardEmpty()) {
            int random_col_index = head->ob->makeFirstMove();
            head->ob->board[0][random_col_index] = 'X';
            head->ob->player = 'X';
            moves_made++;
            game_path_length++;
        }

        minmaxA minmax_object;
        alphabeta alphaBeta_object;

        // assigns the users choice of evaluation function chosen

        if (head->ob->player == 'X' && algo_choiceX == 1) {
            minmax_object.eval_choice = evalfn_choiceX;
            int x = minmax_object.minmaxAB(head, 0, 1000, -1000, head->ob->player);
            moves_made++;
            game_path_length++;
        }

        if (head->ob->player == 'O' && algo_choiceX == 1) {
            minmax_object.eval_choice = evalfn_choiceX;
            int x = minmax_object.minmaxAB(head, 0, 1000, -1000, head->ob->player);
            moves_made++;
            game_path_length++;
        }

        if (head->ob->player == 'X' && algo_choiceX == 2) {
            alphaBeta_object.eval_choice = evalfn_choiceX;
            int x = alphaBeta_object.alpha_beta(head, 0, head->ob->player, 1000, -1000);
            moves_made++;
            game_path_length++;
        }

        if (head->ob->player == 'O' && algo_choiceX == 2) {
            alphaBeta_object.eval_choice = evalfn_choiceX;
            int x = alphaBeta_object.alpha_beta(head, 0, head->ob->player, 1000, -1000);
            moves_made++;
            game_path_length++;
        }
        head->generate_move(board_object, moves_made);
    }
    stop_time = clock();

    return 0;
}

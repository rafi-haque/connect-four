#ifndef TREENODES_H_INCLUDED
#define TREENODES_H_INCLUDED

#include <iostream>

#include "ConnectFourBoard.h"
using namespace std;

extern int num_nodes_generated, num_nodes_expanded, game_path_length, start_time, stop_time;

class tree {
   public:
    // stores the heuristic value of the node i.e board
    int heuristic_value;
    /*to iterate through the children of a node and
    there are exactly 7 possible children for each node
    */
    int num_children;
    // this tores the pointers to its 7 children nodes
    tree *children[7];
    /*an object from the class connectFourBoard which holds the
    board configuration of each node
    */
    connectFourBoard *ob;

    // Member functions of tree class
    tree();
    void create_node(char);
    void set_heuristic_value(int);
    void add_all_children();
    bool deep_enough(int);
    int evaluation1();
    int evaluation2();
    int evaluation3();
    void copy_board_status(connectFourBoard &);
    void helper();
    void print_information();
    int getOptimalNode();
    void generate_move(connectFourBoard *, int);
};
#endif  // TREENODES_H_INCLUDED
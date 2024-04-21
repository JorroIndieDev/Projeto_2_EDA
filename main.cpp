
/*
 * NOTES:
 * (watch video explaining and leave notes here)
 *
 */

#include <iostream>
#include "Headers/structs.h"
#include "Headers/AirportListHandler.h"
#include "Headers/Menus.h"
#include "Headers/init_planes_people.h"
#include "Headers/Aux_functions.h"


int main(int argc, char *argv[]) {
/*
TODO Links de referencia:
 -https://www.youtube.com/watch?v=jDM6_TnYIqE
 -https://www.sanfoundry.com/c-program-create-balanced-binary-tree-incoming-data/


TODO Facam o vosso teste aqui e chamem as funcoes no AirportListHandler.cpp|.h
     as funcoes para a arvore sao as seguintes: (se nao conseguirem deixem me mensagem - Jorro)

// tree handler functions

// make a node with the passenger
Nacionality::Pass_tree * new_tree_node(struct passenger &passenger);

// rotate tree to the right
Nacionality::Pass_tree * rotate_node_to_right(Nacionality::Pass_tree * tree_node);

// rotate tree to the left
Nacionality::Pass_tree * rotate_node_to_left(Nacionality::Pass_tree * tree_node);

// insert node in tree
Nacionality::Pass_tree * insert_tree_node(Nacionality::Pass_tree * tree_node, struct passenger &passenger);

// calculate node height
int node_height(Nacionality::Pass_tree * tree_node);

// DISCART FUNCTION
// funcao vai dar print da arvore
void preOrder(Nacionality::Pass_tree * root);

// get node balance
int get_node_balance(Nacionality::Pass_tree * tree_node);
*/

/***********************************************
 *
 * Facam aqui e testem
 *
 ***********************************************/




/***********************************************
 *
 *
 ***********************************************/


    /*// init rand seed
    srand(time(0));

    // creating struct for holding all Data files
    file_data fileData = file_data();

    // loading Data files provided
    load_files_to_mem(fileData);

    // initialize the airport regardless of args passed
    Airport airport = init_airport();

    // verify if any arg has been parsed
    if (argc > 1) {

        // loads the first argumment parsed aside from ./*.exe
        LoadFromFile(argv[1],airport);

    } else { // if not proceed as normal
        
        // first run of the program initial setup
        for (int i = 0; i < 9; ++i) {
            init_plane(airport, fileData);
        }

    }

    // initialize days / cylces of the airport
    dayCycle(airport,fileData);*/

    return 0;
}

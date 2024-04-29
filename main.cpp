
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

 Notas: as funcoes nao estao todas as necessarias, falta remover e uma funcao dedicada a ordenar
 tecnicamente e so remover parte da insert_tree_node e temos a ordenacao mas e melhor testarmos em cunjunto, se acharem
 que conseguem estejam a vontade, nao se esquecam de comentar as partes importantes tentei deixar tudo o que fiz e fizemos
 comentado a explicar.

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

    srand(time(0));
    file_data fileData = file_data();

    load_files_to_mem(fileData);

    Airport airport = init_airport();

    airport.nacionality_head->nacionality = ' ';
    airport.nacionality_head->next_nacionality = nullptr;
    airport.nacionality_head->root_passenger = nullptr;
    init_plane(airport,fileData);
    Plane::passenger_in_plane * temp = airport.head_arrv->plane.head_passenger;
    airport.nacionality_head->root_passenger = insert_tree_node(airport.nacionality_head->root_passenger,
                                                                temp->passenger);
    while (temp != NULL){
        airport.nacionality_head->root_passenger = insert_tree_node(airport.nacionality_head->root_passenger,
                                                                    temp->passenger);
        temp = temp->next_passenger;
    }

    print2DUtil(airport.nacionality_head->root_passenger,0);
    std::cout << "SPINE\n";
    make_spine(airport.nacionality_head->root_passenger);
    print2DUtil(airport.nacionality_head->root_passenger,0);
    std::cout << "BALENCED\n";
    airport.nacionality_head->root_passenger = balance_tree(airport.nacionality_head->root_passenger);
    print2DUtil(airport.nacionality_head->root_passenger,0);
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

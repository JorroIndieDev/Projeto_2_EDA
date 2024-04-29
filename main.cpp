
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

    srand(time(0));

    // init rand seed
    srand(time(0));

    // creating struct for holding all Data files
    file_data fileData = file_data();

    // loading Data files provided
    load_files_to_mem(fileData);

    // initialize the airport regardless of args passed
    Airport airport = init_airport();


    airport.nacionality_head->nacionality = ' ';
    airport.nacionality_head->next_nacionality = nullptr;
    airport.nacionality_head->root_passenger = nullptr;


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
    Plane::passenger_in_plane * temp;

    temp = airport.head_arrv->plane.head_passenger;
    airport.nacionality_head->root_passenger = insert_tree_node(
            airport.nacionality_head->root_passenger,temp->passenger);
    while (temp != NULL) {
        airport.nacionality_head->root_passenger = insert_tree_node(
                airport.nacionality_head->root_passenger,temp->passenger);
        temp = temp->next_passenger;
    }
    // initialize days / cylces of the airport
    dayCycle(airport,fileData);

    return 0;
}

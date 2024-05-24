
#include <iostream>
#include "Headers/structs.h"
#include "Headers/AirportListHandler.h"
#include "Headers/Menus.h"
#include "Headers/init_planes_people.h"
#include "Headers/Aux_functions.h"


/**
 * main Function is responsible for only initiating the data needed to run the airport, it takes an argument:
 *  -the name of a file that holds the content for the state of a previous airport that was saved
 *      this argument is the name of the file example: "airport" (without quotes and no extention ex: .txt, .dat, etc..)
 */


/*Grupo 19: João Freitas 2058422; João Oliveira 2044423; João Vieira 2103823; José Afonso 2042919; Vanderlan Bezerra 2019523.*/
int main(int argc, char *argv[]) {

    srand(time(0));

    // init rand seed
    srand(time(0));

    // creating struct for holding all Data files
    file_data fileData = file_data();

    // initialize the airport regardless of args passed
    Airport airport;

    // verify if any arg has been parsed
    if (argc > 1) {

        // loads the first argumment parsed aside from ./*.exe

        std::cout << ":";
    }else { // if not proceed as normal

        // loading Data files provided
        load_files_to_mem(fileData);
        listSort(fileData.nacionalidade, fileData.nacionalidade_size);

        airport = init_airport(fileData);

        // first run of the program initial setup
        for (int i = 0; i < 10; ++i) {
            init_plane(airport, fileData);
        }

    }

    // initialize days / cylces of the airport
    dayCycle(airport,fileData);

    return 0;
}

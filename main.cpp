
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


int main() {



    srand(time(0));

    file_data fileData = file_data();

    load_files_to_mem(fileData);

    Airport airport = init_airport();

    // first run of the program initial setup
    for (int i = 0; i < 9; ++i) {
        init_plane(airport,fileData);
    }

    SaveToFile("..\\data\\airport.dat",airport);

    Airport airport2  = init_airport();

    LoadFromFile("..\\data\\airport.dat",airport2);

    log_arrival_planes(airport2);

//    dayCycle(airport,fileData);

    return 0;
}

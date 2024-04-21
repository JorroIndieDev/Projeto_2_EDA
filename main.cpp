
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

    SaveToFile("accounts.dat");

    LoadFromFile("accounts.dat");

   /* srand(time(0));

    file_data fileData = file_data();

    load_files_to_mem(fileData);

    Airport airport = init_airport();

    // first run of the program initial setup
    for (int i = 0; i < 9; ++i) {
        init_plane(airport,fileData);
    }

    dayCycle(airport,fileData);*/

    return 0;
}

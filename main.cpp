
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
/*#include <iostream>
#include <fstream>
#include <string>

const int MAX_LINES = 100; // Define the maximum number of lines

int main() {
    std::ifstream file("../Data_Files/origem.txt"); // Replace "airports.txt" with your file name

    if (!file.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::string lines[MAX_LINES];
    std::string line;
    int count = 0;

    while (std::getline(file, line) && count < MAX_LINES) {
        lines[count] = line;
        count++;
    }

    file.close();

    // Print the read lines
    for (int i = 0; i < count; ++i) {
        std::cout << lines[i] << std::endl;
    }

    return 0;
}*/
int main() {

    srand(time(0));

    file_data fileData;

    load_files_to_mem(fileData);

    Airport airport = init_airport();

    // first run of the program initial setup
    for (int i = 0; i < 9; ++i) {
        init_plane(airport,fileData);
    }

    dayCycle(airport,fileData);

    return 0;
}

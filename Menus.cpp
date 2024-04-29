#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"

void dayCycle(Airport &airport, file_data fileData) {


    bool isWorking = true;

    std::string choice;

    while (isWorking) {

/*        std::cout << "\nLog Arrivals\n" << std::endl;
        log_arrival_planes(airport);
//        log_arrivals_passengers(airport); // change passenger data when moving from list to list
        
        std::cout << "\nLog Ramp\n" << std::endl;
        log_ramp_planes(airport);
//        log_ramp_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\nLog Depart\n" << std::endl;
        log_departure_planes(airport);
//        log_departures_passengers(airport); // change passenger data when moving from list to list
*/
        std::cout << "\n(e)mergencias (o)pcoes (g)ravar (s)next day\n";
        std::cin >> choice;

        std::string name;
        Nacionality::Pass_tree * searchAux;

        switch (choice[0]) {
            case 'e': // Emergency;
                break;
            case 'o': // Options;

                print2DUtil(airport.nacionality_head->root_passenger,0);
                std::cout << "Name? ";
                std::cin >> name;

                airport.nacionality_head->root_passenger = delete_node(
                        airport.nacionality_head->root_passenger,name);
                print2DUtil(airport.nacionality_head->root_passenger,0);

                break;
            case 'g': // Save;
                SaveToFile("airport",airport);
                break;
            // Skip day
            case 's':

                if (airport.num_in_depart > 3){
                    remove_departing_plane(airport);
                }

                if (airport.num_in_ramp == 7) {
                    add_departing_plane(airport,fileData);
                }

                if (airport.num_in_arrival < 10 && !airport.emergency_state) {
                    init_plane(airport , fileData);
                }

                add_ramp_plane(airport,fileData);

                break;

            case 'q': // quit
                isWorking = false;
                break;
            default:
                std::cerr << "Please choose a valid option";
                break;
        }
    }
}
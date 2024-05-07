#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"

void dayCycle(Airport &airport, file_data fileData) {


    bool isWorking = true;

    std::string choice;

    while (isWorking) {

        std::cout << "\nArrivals\n" << std::endl;
        log_planes(airport.head_arrv);

        std::cout << "\nPlanes in Ramp\n" << std::endl;
        log_planes(airport.head_ramp);

        std::cout << "\nDepartures\n" << std::endl;
        log_planes(airport.head_dep);

        std::cout << "\n(e)mergency (o)ptions (l)oad (s)next day\n";
        std::cin >> choice;

        std::string name;
        Nacionality::Pass_tree * searchAux;

        switch (choice[0]) {
            case 'e': // Emergency;
                emergency_handler(airport,fileData);
                break;
            case 'o': // Options;
                option(airport);
                break;
            case 'l': // Save;
                SaveToFile("airport",airport);
                break;
            // Skip day
            case 's':

                airport.cycles_closed = (airport.cycles_closed == 0) ? 0 : airport.cycles_closed-1;
                airport.closed = airport.cycles_closed > 0;

                if (!airport.closed) {

                    if (airport.num_in_arrival > 10) {

                        if (airport.num_in_depart > 3) {
                            remove_departing_plane(airport);
                            remove_departing_plane(airport);
                        }

                        if (airport.num_in_ramp >= 6) {
                            add_departing_plane(airport, fileData);
                            add_departing_plane(airport, fileData);
                        }

                        add_ramp_plane(airport, fileData);
                        add_ramp_plane(airport, fileData);

                    }else {

                        if (airport.num_in_depart > 3) {
                            remove_departing_plane(airport);
                        }

                        if (airport.num_in_ramp >= 6) {
                            add_departing_plane(airport, fileData);
                        }

                        if (airport.num_in_arrival <= 10) {
                            init_plane(airport, fileData);
                        }

                        add_ramp_plane(airport, fileData);
                    }
                }else{
                    init_plane(airport, fileData);
                }
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
// Joao
void option(Airport &airport) {

    int choice;
    std::string newNationality;
    std::cout <<"Choose a option \n"
              << "(1) - Show the passengers on ramp \n"
                 "(2) - Show organized passengers \n"
                 "(3) - Search passengers on arrivals or depart \n"
                 "(4) - Edit a passenger nationality in a arrival plane \n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            log_passengers_in_plane(airport.head_ramp->plane);
            break;
        case 2:
            std::cout << "Ordered alphabetically (1) or Visually (2): ";
            std::cin >> choice;

            if (choice == 1) {
                Nacionality *aux_nacionality;
                aux_nacionality = airport.nacionality_head;

                while (aux_nacionality != nullptr) {
                    std::cout << "Nationality: ";
                    std::cout << aux_nacionality->nacionality << std::endl;
                    print_tree_leftrigt(aux_nacionality->root_passenger, 0);

                    // travessiaInfixa(aux_nacionality->root_passenger);
                    std::cout << std::endl << std::endl;
                    aux_nacionality = aux_nacionality->next_nacionality;
                    //std::cout << aux_nacionality->nacionality;
                }
            }

            std::cout << "\n--------------- END ---------------";
            break;

        case 3:

            std::cout << "Search by departure or arrival\n"
            << "(1) Departure  (2) Arrival";
            std::cin >> choice;

            if (choice == 1)
                search_passengers(airport.head_arrv);
            else if (choice == 2)
                search_passengers(airport.head_dep);
            else
                std::cout << "Invalid choice\n";

            break;

        case 4:
            std::cout << "Which Nationality to be inserted? ";
            std::cin >> newNationality;
            change_nacionality(newNationality,airport);
            break;

        default:
            std::cout << "Choose one of the previous choices\n";
            break;
    }
}
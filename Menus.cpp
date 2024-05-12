#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"
#include <limits>
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

        std::cout << "\n(e)mergency | (c)lose airport | (o)ptions | (l)oad | (s)next day\n";

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

            case 'c':

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

                        arriving_foreigners(airport);
                        add_ramp_plane(airport, fileData);
                        arriving_foreigners(airport);
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

                        arriving_foreigners(airport);
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
    Nacionality *aux_nacionality;

    while (true) {
        std::cout << "Choose a option \n"
                  << "(1) - Show the passengers on ramp \n"
                     "(2) - Show organized passengers \n"
                     "(3) - Search passengers on arrivals or depart \n"
                     "(4) - Edit a passenger nationality in a arrival plane \n"
                     "(5) - Quit to menu\n";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 5) {
            std::cout << "Choose one of the previous choices\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                aux_nacionality = airport.nacionality_head;
                while (aux_nacionality != nullptr) {
                    travessiaInfixa(aux_nacionality->root_passenger);
                    aux_nacionality = aux_nacionality->next_nacionality;
                }
                break;
            case 2:

                aux_nacionality = airport.nacionality_head;

                while (aux_nacionality != nullptr) {
                    if (aux_nacionality->root_passenger == nullptr) {
                        aux_nacionality = aux_nacionality->next_nacionality;
                        continue;
                    }
                    std::cout << "Nationality: ";
                    std::cout << aux_nacionality->nacionality << std::endl;
                    print_tree_leftrigt(aux_nacionality->root_passenger, 0);

                    std::cout << std::endl << std::endl;
                    aux_nacionality = aux_nacionality->next_nacionality;
                }

                break;

            case 3:

                std::cout << "Search by departure or arrival\n"
                          << "(1) Departure  (2) Arrival";
                std::cin >> choice;

                if (choice == 1) {
                    if (airport.head_dep == NULL) {
                        std::cout << "No planes in departure\n";
                        break;
                    }
                    search_passengers(airport.head_dep);

                } else if (choice == 2) {
                    if (airport.head_arrv == NULL) {
                        std::cout << "No planes in Arrival\n";
                        break;
                    }
                    search_passengers(airport.head_arrv);
                } else
                    std::cout << "Invalid choice\n";

                break;

            case 4:
                std::cout << "Which Nationality to be inserted? ";
                std::cin >> newNationality;
                change_nacionality(newNationality, airport);
                break;
            case 5:
                return;
            default:
                std::cout << "Choose one of the previous choices\n";
                break;
        }
    }
}
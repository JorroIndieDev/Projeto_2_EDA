#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"

void dayCycle(Airport &airport, file_data fileData) {


    bool isWorking = true;

    std::string choice;

    while (isWorking) {

        std::cout << "\nLog Arrivals\n" << std::endl;
        log_arrival_planes(airport);
//        log_arrivals_passengers(airport); // change passenger data when moving from list to list
        
        std::cout << "\nLog Ramp\n" << std::endl;
        log_ramp_planes(airport);
//        log_ramp_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\nLog Depart\n" << std::endl;
        log_departure_planes(airport);
//        log_departures_passengers(airport); // change passenger data when moving from list to list


       /* reverse_arrival(airport);
        reverse_departing(airport);
        reverse_ramp(airport);
        std::cout << std::endl << std::endl << std::endl << "TROCA TROCA" << std::endl << std::endl;

        std::cout << "\nLog Arrivals\n" << std::endl;
        log_arrival_planes(airport);
        log_arrivals_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\nLog Ramp\n" << std::endl;
        log_ramp_planes(airport);
        log_ramp_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\nLog Depart\n" << std::endl;
        log_departure_planes(airport);
        log_departures_passengers(airport); // change passenger data when moving from list to list
*/

        std::cout << "\n(e)mergencias (o)pcoes (g)ravar (s)next day\n";
        std::cin >> choice;

        switch (choice[0]) {
            case 'e': // Emergency;
                break;
            case 'o': // Options;
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
// Joao | Afonso ajudou com algumas opcoes
void option(Airport &airport) {
    int choice;
    std::cout << "Mostrar todos os passageiros em pista (1), ordenados(2): \n"
                 "Pesquisar passageiro nas chegadas e partidas (3)\n"
                 "Editar nacionalidade de um passageiro num voo das chegadas (4)\n"
                 "Escolha uma das opçoes anteriores: ";
    std::cin >> choice;

    switch (choice) {
        //Afonso está a mexer nisto
        case 1:
            std::cout << "Todos os passageiros em pista: ";
            break;
        //------------------> Final da parte do afonso
        case 2:
            std::cout << "Ordenados alfabeticamente(1) ou arvore binaria(2): ";
            std::cin >> choice;

            if (choice == 1) {
                Nacionality *aux_nacionality;
                aux_nacionality = airport.nacionality_head;

                while (aux_nacionality != nullptr) {
                    std::cout << "Nacionalidade: ";
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
            passenger * search_passengers(Airport &airport);
            break;
    }
}
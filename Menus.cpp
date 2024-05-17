#include "Headers/Menus.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"
<<<<<<< Updated upstream

void dayCycle(Airport &airport, file_data fileData) {
=======
#include <limits>
>>>>>>> Stashed changes

/**
 * Simula um ciclo diário de um aeroporto, mostrando todos os aviões na chegada, pista e a descolar.
 * @param airport - Referência para o objeto Airport
 * @param fileData - Objeto contendo todas as informações relacionadas aos arquivos do airport
 */
void dayCycle(Airport &airport, file_data fileData) {

    bool isWorking = true;

    std::string choice;

    while (isWorking) {

        std::cout << "\nLog Arrivals\n" << std::endl;
//        log_arrival_planes(airport);
        //log_arrivals_passengers(airport); // change passenger data when moving from list to list
        
        std::cout << "\nLog Ramp\n" << std::endl;
//        log_ramp_planes(airport);
        //log_ramp_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\nLog Depart\n" << std::endl;
//        log_departure_planes(airport);
        //log_departures_passengers(airport); // change passenger data when moving from list to list

        std::cout << "\n(e)mergencias (o)pcoes (g)ravar (s)next day\n";
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
            case 'g': // Save;
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

                        if (airport.num_in_arrival <= 10 && !airport.emergency_state) {
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
/** Age como o menu de diferentes opções que o usuário pode escolher para interagir com o
 * programa, sendo que pode escolher respetivamente:
 *  -Visualizar os passageiros na rampa;
 *  -Apresentar árvore de passageiros ordenada do ponto de vista do utilizador;
 *  -Procurar os passageiros quer nas chegadas, quer nas saídas pelo seu nome;
 *  -Editar a nacionalidade de um passageiro num avião que esteja a chegar;
 *  -Inverter a prioridade dos aviões que se encontram na rampa;
 *  -Voltar ao menu principal;
 *
 * @param airport - passa um parâmetro do tipo Airport para poder manipulá-lo e percorrê-lo
 * */
void option(Airport &airport) {
    int choice;
    std::cout << "Mostrar todos os passageiros em pista (1), ordenados(2): \n"
                 "Pesquisar passageiro nas chegadas e partidas (3)\n"
                 "Editar nacionalidade de um passageiro num voo das chegadas (4)\n"
                 "Escolha uma das opçoes anteriores: ";
    std::cin >> choice;

    switch (choice) {
        case 2:
            std::cout << "Ordenados alfabeticamente(1) ou arovere binaria(2): ";
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
    }
}
//
// Created by goliv on 4/17/2024.
//

#include "Headers/init_planes_people.h"
#include "Headers/AirportListHandler.h"



void init_plane(Airport &airport, file_data &fileData ){

    Plane newPlane;

    newPlane.flight_name = fileData.voo[random_range(0, fileData.voo_size - 1)];
    newPlane.model = fileData.modelo[random_range(0, fileData.modelo_size - 1)];
    newPlane.origin = fileData.origem[random_range(0, fileData.origem_size - 1)];
    newPlane.destination = "AeroportoEDA";
    newPlane.capacity = random_range(5, 15);
    newPlane.head_passenger = nullptr;

    init_passengers(newPlane,fileData);
    add_arriving_plane(airport, newPlane);

}

void init_passengers(Plane &plane , file_data fileData){

    for (int i = 0; i < plane.capacity; ++i) {

        passenger newPassenger;
        fileData.ticket_number += i;
        newPassenger.ticket_num = (fileData.Ticket + std::to_string(fileData.ticket_number));
        newPassenger.first_name = fileData.primeiro_nome[random_range(0,fileData.primeiro_nome_size-1)];
        newPassenger.second_name = fileData.segundo_nome[random_range(0,fileData.segundo_nome_size-1)];
        newPassenger.nacionality = fileData.nacionalidade[random_range(0,fileData.nacionalidade_size-1)];

        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;
        passNode->passenger = newPassenger;
        passNode->next_passenger = NULL;

        if (plane.head_passenger == NULL) {
            plane.head_passenger = passNode;
        }
        else {
            Plane::passenger_in_plane * temp_passenger_in_plane = plane.head_passenger;

            // Traverse to the last node of the linked list
            while (temp_passenger_in_plane->next_passenger != NULL) {
                temp_passenger_in_plane = temp_passenger_in_plane->next_passenger;
            }
            // Attach passNode to the end of the list
            if (temp_passenger_in_plane != NULL) {
                temp_passenger_in_plane->next_passenger = passNode;
            }
        }
    }
}


Airport init_airport(){

    Airport airport;

    airport.emergency_state = false;
    // Nacionality
    airport.nacionality_head = nullptr;

    // Arrival
    airport.head_arrv = nullptr;
    airport.num_in_arrival = 0;
    airport.arrival_cap = 9;

    // Depart
    airport.head_dep = nullptr;
    airport.depart_cap = 4;
    airport.num_in_depart = 0;

    // Ramp
    airport.head_ramp = nullptr;
    airport.ramp_cap = 6;
    airport.num_in_ramp = 0;

    return airport;
}
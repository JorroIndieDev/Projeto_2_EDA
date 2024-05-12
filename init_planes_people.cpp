//
// Created by goliv on 4/17/2024.
//

#include "Headers/init_planes_people.h"
#include "Headers/AirportListHandler.h"



void init_plane(Airport &airport, file_data &fileData ) {

    // create new plane to add to the list of arrivals
    Plane newPlane;

    // init the plane with default params
    newPlane.flight_name = fileData.voo[random_range(0, fileData.voo_size - 1)];
    newPlane.model = fileData.modelo[random_range(0, fileData.modelo_size - 1)];
    newPlane.origin = fileData.origem[random_range(0, fileData.origem_size - 1)];
    newPlane.capacity = random_range(5, 15);

    // initiate nullptr to not get magic values
    newPlane.head_passenger = nullptr;

    // all planes are initiated with AeroportoEDA as destination
    newPlane.destination = "AeroportoEDA";

    // call functions to initiate plane passengers to the plane and add them to the list
    init_passengers(newPlane,fileData);
    add_arriving_plane(airport, newPlane);

}

void init_home_passengers(Plane &plane , file_data &fileData, int num_of_passengers) {
    int i;
    if (num_of_passengers == 0) num_of_passengers=plane.capacity;
    for (i = 0; i < num_of_passengers; ++i) {

        // create a passenger to be added to the plane passenger list
        passenger newPassenger;

        // init passenger
        newPassenger.ticket_num = (fileData.Ticket + std::to_string(fileData.ticket_number + i));
        newPassenger.first_name = fileData.primeiro_nome[random_range(0,fileData.primeiro_nome_size-1)];
        newPassenger.second_name = fileData.segundo_nome[random_range(0,fileData.segundo_nome_size-1)];
        newPassenger.nacionality = "Portuguese";

        // init a node to the passengers in the plane
        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;

        // since its a linked list we add the passenger to its ::passenger
        passNode->passenger = newPassenger;
        // then init ::next to null
        passNode->next_passenger = NULL;

        // if "head" is null we add to the head
        if (plane.head_passenger == NULL) {
            plane.head_passenger = passNode;
        } // else we loop and add at the end of the list
        else {

            // new aux var to traverse the list without destroying it
            Plane::passenger_in_plane * temp_passenger_in_plane = plane.head_passenger;

            // loop until null
            while (temp_passenger_in_plane->next_passenger != NULL) {
                temp_passenger_in_plane = temp_passenger_in_plane->next_passenger;
            }
            // add node to the list
            if (temp_passenger_in_plane != NULL) {
                temp_passenger_in_plane->next_passenger = passNode;
            }
        }
    }
    fileData.ticket_number = fileData.ticket_number + i;
}

void init_passengers(Plane &plane , file_data &fileData, int num_of_passengers) {
    int i;
    if (num_of_passengers == 0) num_of_passengers=plane.capacity;
    for (i = 0; i < num_of_passengers; ++i) {

        // create a passenger to be added to the plane passenger list
        passenger newPassenger;

        // init passenger
        newPassenger.ticket_num = (fileData.Ticket + std::to_string(fileData.ticket_number + i));
        newPassenger.first_name = fileData.primeiro_nome[random_range(0,fileData.primeiro_nome_size-1)];
        newPassenger.second_name = fileData.segundo_nome[random_range(0,fileData.segundo_nome_size-1)];
        newPassenger.nacionality = fileData.nacionalidade[random_range(0,fileData.nacionalidade_size-1)];

        // init a node to the passengers in the plane
        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;

        // since its a linked list we add the passenger to its ::passenger
        passNode->passenger = newPassenger;
        // then init ::next to null
        passNode->next_passenger = NULL;

        // if "head" is null we add to the head
        if (plane.head_passenger == NULL) {
            plane.head_passenger = passNode;
        } // else we loop and add at the end of the list
        else {

            // new aux var to traverse the list without destroying it
            Plane::passenger_in_plane * temp_passenger_in_plane = plane.head_passenger;

            // loop until null
            while (temp_passenger_in_plane->next_passenger != NULL) {
                temp_passenger_in_plane = temp_passenger_in_plane->next_passenger;
            }
            // add node to the list
            if (temp_passenger_in_plane != NULL) {
                temp_passenger_in_plane->next_passenger = passNode;
            }
        }
    }
    fileData.ticket_number = fileData.ticket_number + i;
}

Airport init_airport(file_data fileData) {

    // function simply inits the airport to null values and sizes of the arrays

    Airport airport;

    airport.emergency_state = false;

    // Nacionality
    airport.nacionality_head = nullptr;
    populate_nacionalityList(airport,fileData);
    airport.nacionality_head->root_passenger = nullptr;

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

    // return initiated airport
    return airport;
}

void populate_nacionalityList(Airport &airport, file_data fileData){
    airport.nacionality_size = fileData.nacionalidade_size-1;
    for (int i = 0; i < fileData.nacionalidade_size; ++i) {
        if (fileData.nacionalidade[i] == "Portuguese")continue;

        Nacionality * temp = new Nacionality;
        temp->nacionality = fileData.nacionalidade[i];
        temp->next_nacionality = nullptr;

        if (airport.nacionality_head == NULL){
            airport.nacionality_head = temp;
            airport.nacionality_head->root_passenger = nullptr;
        }
        else{
            Nacionality * aux = airport.nacionality_head;
            while (aux->next_nacionality != NULL){
                aux = aux->next_nacionality;
            }
            aux->next_nacionality = temp;
            aux->next_nacionality->root_passenger = nullptr;
        }

    }

}
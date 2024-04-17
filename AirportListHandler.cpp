//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"

void remove_departing_plane(Airport &airport){
    if (airport.head_dep == NULL)return; // if head is NULL list is empty

    Airport::Depart * temp = airport.head_dep;
    airport.head_dep = airport.head_dep->next;
    airport.num_in_depart--;

}

void add_departing_plane(Airport &airport){
    if (airport.head_ramp == NULL)return;

    // remove from ramp
    Airport::Ramp * temp = airport.head_ramp;
    airport.head_ramp = airport.head_ramp->next;
    airport.num_in_ramp--;

    // add to depart
    Airport::Depart *new_depart = new Airport::Depart;
    new_depart->plane = temp->plane;
    new_depart->next = nullptr;

    if (airport.head_dep == NULL){
        airport.head_dep = new_depart;

    }else {
        Airport::Depart *ptr = airport.head_dep;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_depart;
    }

    delete temp;
}

void log_departures(Airport &airport){
    std::cout << "-------------------\n";
    if (!airport.head_dep) {
        std::cout << "No departing planes.\n";
        return;
    }

    Airport::Depart *departNode = airport.head_dep;

    while (departNode) {
        std::cout << "Departing Plane: " << departNode->plane.flight_name << "\n";
        std::cout << "Model: " << departNode->plane.model << ", ";
        std::cout << "Origin: " << departNode->plane.origin << ", ";
        std::cout << "Destination: " << departNode->plane.destination << "\n";

        Plane::passenger_in_plane *passNode = departNode->plane.head_pass;
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->pass.ticket_num << ", ";
            std::cout << "Name: " << passNode->pass.first_name << " " << passNode->pass.second_name << ", ";
            std::cout << "Nationality: " << passNode->pass.nacionality << "\n";
            passNode = passNode->next_pass;
        }

        if (departNode->next) {
            std::cout << "\nNext Departing Plane: " << departNode->next->plane.flight_name << "\n";
        }

        departNode = departNode->next;
        if (departNode) {
            std::cout << "-------------------\n";  // Separator between planes
        }
    }
}



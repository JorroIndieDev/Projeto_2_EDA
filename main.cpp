#include <iostream>
#include <stdlib.h>
#include "Headers/structs.h"
#include "Headers/AirportListHandler.h"

/*
 * NOTES:
 * (watch video explaining and leave notes here)
 *
 *
 */


int main() {

    //TODO
    // Create an Airport object
    Airport airport;

    // Initialize Airport
    airport.nacionality_head = nullptr;
    airport.head_ramp = nullptr;
    airport.num_in_ramp = 0;
    airport.head_dep = nullptr;
    airport.num_in_depart = 0;
    airport.head_arrv = nullptr;
    airport.num_in_arrival = 0;

    // Create a Plane for demo
    Plane plane;
    plane.flight_name = "Flight001";
    plane.model = "Boeing 747";
    plane.origin = "New York";
    plane.destination = "Los Angeles";
    plane.capacidade = 50;
    plane.quantity = 5;  // Let's say 250 passengers

    // Add passengers to the plane
    for (int i = 0; i < plane.quantity; ++i) {
        passenger newPassenger;
        newPassenger.ticket_num = i + 1;  // Ticket numbers start from 1
        newPassenger.first_name = "John";
        newPassenger.second_name = "Doe";
        newPassenger.nacionality = "USA";

        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;
        passNode->pass = newPassenger;
        passNode->next_pass = nullptr;

        if (!plane.head_pass) {
            plane.head_pass = passNode;
        } else {
            Plane::passenger_in_plane *temp = plane.head_pass;
            while (temp->next_pass) {
                temp = temp->next_pass;
            }
            temp->next_pass = passNode;
        }
    }

    // Add plane to ramp
    Airport::Ramp *rampNode = new Airport::Ramp;
    rampNode->plane = plane;
    rampNode->next = NULL;

    airport.head_ramp = rampNode;
    airport.num_in_ramp++;

    // Create a Plane for demonstration
    Plane plane2;
    plane2.flight_name = "Flight002";
    plane2.model = "Boeing 745";
    plane2.origin = "New York";
    plane2.destination = "Los Angeles";
    plane2.capacidade = 50;
    plane2.quantity = 5;  // Let's say 250 passengers

    // Add passengers to the plane
    for (int i = 0; i < plane2.quantity; ++i) {
        passenger newPassenger;
        newPassenger.ticket_num = i + 1;  // Ticket numbers start from 1
        newPassenger.first_name = "Ann";
        newPassenger.second_name = "Doe";
        newPassenger.nacionality = "POOP";

        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;
        passNode->pass = newPassenger;
        passNode->next_pass = nullptr;

        if (!plane2.head_pass) {
            plane2.head_pass = passNode;
        } else {
            Plane::passenger_in_plane *temp = plane2.head_pass;
            while (temp->next_pass) {
                temp = temp->next_pass;
            }
            temp->next_pass = passNode;
        }
    }
    Airport::Ramp *rampNode2 = new Airport::Ramp;
    rampNode2->plane = plane2;
    rampNode2->next = NULL;
    airport.head_ramp->next = rampNode2;
    airport.num_in_ramp++;

// Print the planes in the ramp as a demonstration
    if (airport.head_ramp) {
        std::cout << "Planes in Ramp:\n";
        Airport::Ramp *rampNode = airport.head_ramp;
        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "No planes in the ramp.\n";
    }

// Add departing plane to depart list
    add_departing_plane(airport);
    add_departing_plane(airport);

// Print the departing plane's passengers as a demonstration
    if (airport.head_ramp) {
        std::cout << "Planes in Ramp:\n";
        Airport::Ramp *rampNode = airport.head_ramp;
        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "No planes in the ramp.\n";
    }
    log_departures(airport);

// Remove departing plane
    remove_departing_plane(airport);

// Print the updated departing plane's passengers

// Clean up memory (you might want to implement a function to do this properly)
    while (airport.head_ramp) {
        Airport::Ramp *temp = airport.head_ramp;
        airport.head_ramp = airport.head_ramp->next;
        delete temp;
    }

    return 0;

}
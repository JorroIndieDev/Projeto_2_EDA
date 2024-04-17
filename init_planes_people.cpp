//
// Created by goliv on 4/17/2024.
//

#include "Headers/init_planes_people.h"
#include "Headers/AirportListHandler.h"


void init_plane(Airport &airport){
    Plane newPlane;
    newPlane.flight_name = "FlightPOOP";
    newPlane.model = "MegaPOOP";
    newPlane.origin = "POOPLAND";
    newPlane.destination = "NO";
    newPlane.quantity = 5;
    newPlane.capacity = 5;
    init_passengers(newPlane);
    add_arriving_plane(airport,newPlane);
}

void init_passengers(Plane &plane){
    for (int i = 0; i < plane.quantity; ++i) {

        passenger newPassenger;
        newPassenger.ticket_num = i + 1;  // Ticket numbers start from 1
        newPassenger.first_name = "joe";
        newPassenger.second_name = "Doe";
        newPassenger.nacionality = "POOP_land";

        Plane::passenger_in_plane *passNode = new Plane::passenger_in_plane;
        passNode->passenger = newPassenger;
        passNode->next_passenger = NULL;

        if (plane.head_passenger == NULL) {
            plane.head_passenger = passNode;
        } else {
            Plane::passenger_in_plane * temp_passenger_in_plane = plane.head_passenger;
            while (temp_passenger_in_plane->next_passenger != NULL) {
                temp_passenger_in_plane = temp_passenger_in_plane->next_passenger;
            }
            temp_passenger_in_plane->next_passenger = passNode;
        }
    }
}

Airport init_airport(){

}
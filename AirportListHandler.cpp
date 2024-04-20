//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"

void remove_departing_plane(Airport &airport){
    if (airport.head_dep == NULL)return; // if head is NULL list is empty
//    std::cerr << "Removing depart Plane";
    Airport::Depart * temp = airport.head_dep;
    airport.head_dep = airport.head_dep->next;
    airport.num_in_depart--;
    delete temp;
}

void add_arriving_plane(Airport &airport, Plane &plane){

//    std::cerr << "Adding Arrival Plane\n";

    Airport::Arrival * new_depart = new Airport::Arrival;
    new_depart->plane = plane;
    new_depart->next = nullptr;

    if (airport.head_arrv == NULL){
        airport.head_arrv = new_depart;

    }else {
        Airport::Arrival * ptr = airport.head_arrv;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_depart;
        airport.num_in_arrival++;
    }
}

void add_departing_plane(Airport &airport){
    if (airport.head_ramp == NULL)return;
//    std::cerr << "Adding Depart Plane\n";

    // remove from ramp
    Airport::Ramp * temp = airport.head_ramp;
    airport.head_ramp = airport.head_ramp->next;
    airport.num_in_ramp--;

    // add to depart
    Airport::Depart * new_depart = new Airport::Depart;
    new_depart->plane = temp->plane;
    new_depart->next = nullptr;

    if (airport.head_dep == NULL){
        airport.head_dep = new_depart;

    }else {
        Airport::Depart * ptr = airport.head_dep;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_depart;
        airport.num_in_depart++;
    }

    delete temp;
}

void add_ramp_plane(Airport &airport){
    if (airport.head_arrv == NULL)return;
//    std::cerr << "Adding Ramp Plane\n";

    // remove from arrival
    Airport::Arrival * temp = airport.head_arrv;
    airport.head_arrv= airport.head_arrv->next;
    airport.num_in_arrival--;

    // add to ramp
    Airport::Ramp * new_arrival_to_ramp = new Airport::Ramp;
    new_arrival_to_ramp->plane = temp->plane;
    new_arrival_to_ramp->next = nullptr;

    if (airport.head_ramp == NULL){
        airport.head_ramp = new_arrival_to_ramp;

    }else {
        Airport::Ramp *ptr = airport.head_ramp;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_arrival_to_ramp;
        airport.num_in_ramp++;
    }

    delete temp;
}

void log_departures_passengers(Airport &airport){
    std::cout << "\n---------Departing passengers----------\n";
    if (!airport.head_dep) {
        std::cout << "\nNo planes in departure.\n";
        return;
    }

    Airport::Depart * depart_ptr = airport.head_dep;

    while (depart_ptr != NULL) {
        std::cout << "Departing Plane: " << depart_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << depart_ptr->plane.model << ", ";
        std::cout << "Origin: " << depart_ptr->plane.origin << ", ";
        std::cout << "Destination: " << depart_ptr->plane.destination << "\n";

        Plane::passenger_in_plane * passNode = depart_ptr->plane.head_passenger;
        if (!passNode) std::cout << "Departure Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        if (depart_ptr->next) {
            std::cout << "\nNext Departing Plane: " << depart_ptr->next->plane.flight_name << "\n";
        }

        depart_ptr = depart_ptr->next;

        std::cout << "\n|-------------------|\n";
    }
}

void log_ramp_passengers(Airport &airport){
    std::cout << "\n----------Ramp passengers in Plane---------\n";
    if (!airport.head_ramp) {
        std::cout << "\nNo planes in ramp.\n";
        return;
    }

    Airport::Ramp * ramp_ptr = airport.head_ramp;

    while (ramp_ptr) {
        std::cout << "Ramp Plane: " << ramp_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << ramp_ptr->plane.model << ", ";
        std::cout << "Origin: " << ramp_ptr->plane.origin << ", ";
        std::cout << "Destination: " << ramp_ptr->plane.destination << "\n";

        Plane::passenger_in_plane *passNode = ramp_ptr->plane.head_passenger;
        if (!passNode) std::cout << "Ramp Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        if (ramp_ptr->next) {
            std::cout << "\nNext Plane to depart: " << ramp_ptr->next->plane.flight_name << "\n";
        }

        ramp_ptr = ramp_ptr->next;

        std::cout << "\n-------------------\n";
    }
}

void log_arrivals_passengers(Airport &airport){
    std::cout << "\n---------Ariving passengers----------\n";
    if (!airport.head_arrv) {
        std::cout << "\nNo planes arriving.\n";
        return;
    }

    Airport::Arrival * arr_ptr = airport.head_arrv;

    while (arr_ptr) {
        std::cout << "Ariving Plane: " << arr_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << arr_ptr->plane.model << ", ";
        std::cout << "Origin: " << arr_ptr->plane.origin << ", ";
        std::cout << "Destination: " << arr_ptr->plane.destination << "\n";

        Plane::passenger_in_plane * passNode = arr_ptr->plane.head_passenger;
        if (!passNode) std::cout << "Arrival Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        if (arr_ptr->next) {
            std::cout << "\nNext plane arriving: " << arr_ptr->next->plane.flight_name << "\n";
        }

        arr_ptr = arr_ptr->next;

        std::cout << "\n-------------------\n";
    }
}

void log_ramp_planes(Airport &airport){
    if (airport.head_ramp) {
        std::cout << "\nPlanes in Ramp:\n";
        Airport::Ramp *rampNode = airport.head_ramp;
        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes in the ramp.\n";
    }
}

void log_arrival_planes(Airport &airport){
    if (airport.head_arrv) {
        std::cout << "\nPlanes ariving:\n";
        Airport::Arrival *rampNode = airport.head_arrv;
        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes ariving.\n";
    }
}

void log_departure_planes(Airport &airport){
    if (airport.head_dep) {
        std::cout << "\nPlanes in departure:\n";
        Airport::Depart *rampNode = airport.head_dep;
        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes on departure\n";
    }
}
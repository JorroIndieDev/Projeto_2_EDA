//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"

void remove_departing_plane(Airport &airport){
    if (airport.head_dep == NULL)return; // if head is NULL list is empty

    // since we parse  address we create a temp var to delete it afterward so that there is no memory leak
    Airport::Depart * temp = airport.head_dep;
    airport.head_dep = airport.head_dep->next;
    airport.num_in_depart--;

    // delete temp var
    delete temp;
}

void add_arriving_plane(Airport &airport, Plane &plane){

    // create new Arrival node to add to list
    Airport::Arrival * new_arrv = new Airport::Arrival;
    new_arrv->plane = plane;
    new_arrv->next = nullptr;

    // if head NULL add at the head
    if (airport.head_arrv == NULL){
        airport.head_arrv = new_arrv;

    }else { // else add at the end
        Airport::Arrival * ptr = airport.head_arrv;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_arrv;
        airport.num_in_arrival++;
    }
}

void add_departing_plane(Airport &airport, file_data &fileData){
    if (airport.head_ramp == NULL)return;

    // remove from ramp
    Airport::Ramp * temp = airport.head_ramp;
    airport.head_ramp = airport.head_ramp->next;
    airport.num_in_ramp--;

    // change destination and origin
    temp->plane.destination = fileData.destino[random_range(0,fileData.destino_size-1)];
    temp->plane.origin = "AeroportoEDA";

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

void add_ramp_plane(Airport &airport, file_data &fileData){
    if (airport.head_arrv == NULL)return;

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

void reverse_departing(Airport &airport) {

    // aux vars to reverse the links
    Airport::Depart * current_plane = airport.head_dep;
    Airport::Depart * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;

    }

    // assign new head with links fixed to the actual head
    airport.head_dep = prev_plane;

}

void reverse_ramp(Airport &airport) {

    // aux vars to reverse the links
    Airport::Ramp * current_plane = airport.head_ramp;
    Airport::Ramp * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;

    }

    // assign new head with links fixed to the actual head
    airport.head_ramp = prev_plane;

}

void reverse_arrival(Airport &airport) {

    // aux vars to reverse the links
    Airport::Arrival * current_plane = airport.head_arrv;
    Airport::Arrival * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;
    }

    // assign new head with links fixed to the actual head
    airport.head_arrv = prev_plane;

}

void log_departures_passengers(Airport &airport){
    std::cout << "\n---------Departing passengers----------\n";
    if (!airport.head_dep) {
        std::cout << "\nNo planes in departure.\n";
        return;
    }

    // creates aux var to traverse linked list to not destroy it
    Airport::Depart * depart_ptr = airport.head_dep;

    while (depart_ptr != NULL) {
        std::cout << "Departing Plane: " << depart_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << depart_ptr->plane.model << ", ";
        std::cout << "Origin: " << depart_ptr->plane.origin << ", ";
        std::cout << "Destination: " << depart_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane * passNode = depart_ptr->plane.head_passenger;

        if (!passNode) std::cout << "Departure Plane Empty\n";

        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
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

    // creates aux var to traverse linked list to not destroy it
    Airport::Ramp * ramp_ptr = airport.head_ramp;

    while (ramp_ptr) {
        std::cout << "Ramp Plane: " << ramp_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << ramp_ptr->plane.model << ", ";
        std::cout << "Origin: " << ramp_ptr->plane.origin << ", ";
        std::cout << "Destination: " << ramp_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane *passNode = ramp_ptr->plane.head_passenger;

        if (!passNode) std::cout << "Ramp Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
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

    // creates aux var to traverse linked list to not destroy it
    Airport::Arrival * arr_ptr = airport.head_arrv;

    while (arr_ptr) {
        std::cout << "Ariving Plane: " << arr_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << arr_ptr->plane.model << ", ";
        std::cout << "Origin: " << arr_ptr->plane.origin << ", ";
        std::cout << "Destination: " << arr_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane * passNode = arr_ptr->plane.head_passenger;
        if (!passNode) std::cout << "Arrival Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        arr_ptr = arr_ptr->next;

        std::cout << "\n-------------------\n";
    }
}

void log_ramp_planes(Airport &airport){

    if (airport.head_ramp) {

        std::cout << "\nPlanes in Ramp:\n";

        // creates aux var to traverse linked list to not destroy it
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

        // creates aux var to traverse linked list to not destroy it
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

        // creates aux var to traverse linked list to not destroy it
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
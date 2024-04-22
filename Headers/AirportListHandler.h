//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AIRPORTLISTHANDLER_H
#define PROJETO_2_AIRPORTLISTHANDLER_H

#include "structs.h"
#include "Aux_functions.h"
#include <iostream>

/*
 * Possibility of having the airport handle all of this
 *
 * just have one function to handle this logic
 * if arriving -> ramp
 * if ramp -> depart
 *
 * seperate function to handle passengers from arriving to ramp
 * linked list handler
 *
 * seperate function to handle passengers from ramp to depart
 * tree handler
 *
 */

void passengers_to_ramp(Airport &airport);

// Add to arrival list FIFO
void add_arriving_plane(Airport &airport, Plane &plane);

// Remove from arrival FIFO

// Add to depart list FIFO
void add_departing_plane(Airport &airport, file_data &fileData);

// Remove from depart list FIFO
void remove_departing_plane(Airport &airport);

// Add to ramp list FIFO
void add_ramp_plane(Airport &airport, file_data &fileData);

// Show lists
// log functions simply laod the information of the pasengers in each list
void log_departures_passengers(Airport &airport);
void log_ramp_passengers(Airport &airport);
void log_arrivals_passengers(Airport &airport);

void log_ramp_planes(Airport &airport);
void log_arrival_planes(Airport &airport);
void log_departure_planes(Airport &airport);

// Reverse the airport
void reverse_departing(Airport &airport);
void reverse_ramp(Airport &airport);
void reverse_arrival(Airport &airport);

#endif //PROJETO_2_AIRPORTLISTHANDLER_H

//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AIRPORTLISTHANDLER_H
#define PROJETO_2_AIRPORTLISTHANDLER_H

#include "structs.h"

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

// Add to depart list FIFO
void add_departing_plane(Airport &airport);
// Remove from depart list FIFO
void remove_departing_plane(Airport &airport);
// Add to ramp list FIFO

// Show lists
void log_departures(Airport &airport);
#endif //PROJETO_2_AIRPORTLISTHANDLER_H

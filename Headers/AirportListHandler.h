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

// add passagers to the plane in departure
void add_passengers(Airport &airport, Plane &plane, file_data &fileData);

//show planes
void log_planes(llnode * list);

//show passengeres in the plane @param plane
void log_passengers_in_plane(Plane plane);

// tree handler functions

// make a node with the passenger
Nacionality::Pass_tree * new_tree_node(struct passenger &passenger);

// insert node in tree
Nacionality::Pass_tree * insert_tree_node(Nacionality::Pass_tree * tree_node, struct passenger &passenger);

void print_tree_leftrigt(Nacionality::Pass_tree* root, int space);

Nacionality::Pass_tree * delete_node(Nacionality::Pass_tree * root, std::string name);

Nacionality::Pass_tree * search_namesTree(Nacionality::Pass_tree * root,std::string name);

// Reverse the airport
void reverse_departing(Airport &airport);
void reverse_ramp(Airport &airport);
void reverse_arrival(Airport &airport);

void emergency_handler(Airport &airport,file_data &fileData);

void remove_passengers(Airport &airport);

void travessiaInfixa(Nacionality::Pass_tree *nacionality);
void log_passenger(passenger *passageiro);
void listSort(std::string list[], int list_size);

void arriving_foreigners(Airport &airport);
passenger * search_passengers(llnode *list);
void change_nacionality(std::string newNationality, Airport &airport);

#endif //PROJETO_2_AIRPORTLISTHANDLER_H

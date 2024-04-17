//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_STRUCTS_H
#define PROJETO_2_STRUCTS_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

struct passenger{ // passenger "object"

    int ticket_num;

    std::string first_name;
    std::string second_name;
    std::string nacionality;

};

struct Plane{ // plane "object"

    std::string flight_name;
    std::string model;
    std::string origin;
    std::string destination;

    int capacidade;
    int quantity;

    struct passenger_in_plane{ // node to the linked list of passengers

        passenger pass;

        passenger_in_plane * next_pass;

    };
    passenger_in_plane * head_pass;
};

struct Nacionality{ // linked list of nacionalities

    std::string nacionality;

    struct Pass_tree{ // tree of passengers

        passenger * pass;

        Pass_tree * left;
        Pass_tree * right;

    };

    Pass_tree * root;

    struct Nacionality * next_nacionality;

};



struct Airport{ // airport "Parent"

    // pool of passengers in ramp ordered by nacionality
    struct Nacionality * nacionality_head;

    // Airport lists arr,ramp,departure FIFO's
    struct Ramp{ // ramp can be planes to depart and planes arriving
        Plane plane;
        Ramp * next;
    };

    Ramp * head_ramp;
    int ramp_cap;
    int num_in_ramp;

    struct Depart{
        Plane plane;
        Depart * next;
    };

    Depart * head_dep;
    int depart_cap;
    int num_in_depart;

    struct Arrival{
        Plane plane;
        Arrival * next;
    };

    Arrival * head_arrv;
    int arrival_cap;
    int num_in_arrival;

};

#endif //PROJETO_2_STRUCTS_H

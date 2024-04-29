//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_STRUCTS_H
#define PROJETO_2_STRUCTS_H

#include <iostream>

struct passenger{ // passenger "object"

    std::string ticket_num;
    std::string first_name;
    std::string second_name;
    std::string nacionality;

};

struct Plane{ // plane "object"

    std::string flight_name;
    std::string model;
    std::string origin;
    std::string destination;

    int capacity; //Por favor considerem a capacidade entre 5 a 15

    struct passenger_in_plane{ // node to the linked list of passengers

        struct passenger passenger;
        passenger_in_plane * next_passenger;

    };
    passenger_in_plane * head_passenger;
};

struct Nacionality{ // linked list of nacionalities

    std::string nacionality;

    struct Pass_tree{ // tree of passengers

        struct passenger passenger;

        Pass_tree * left;
        Pass_tree * right;

    };

    Pass_tree * root_passenger;

    struct Nacionality * next_nacionality;

};



struct Airport{ // airport "Parent"

    // pool of passengers in ramp ordered by nacionality
    struct Nacionality * nacionality_head;


    // Airport lists arr,ramp,departure FIFO's

    // Max size -> 7 , 0 to 6
    struct Ramp{ // ramp can be planes to depart and planes arriving
        Plane plane;
        Ramp * next;
    };

    Ramp * head_ramp;
    int ramp_cap;
    int num_in_ramp;

    // Max size -> 5
    struct Depart{
        Plane plane;
        Depart * next;
    };

    Depart * head_dep;
    int depart_cap;
    int num_in_depart;

    // Max size -> 10
    struct Arrival{
        Plane plane;
        Arrival * next;
    };

    Arrival * head_arrv;
    int arrival_cap;
    int num_in_arrival;

    // Emergency Status
    bool emergency_state = false;
};

#endif //PROJETO_2_STRUCTS_H

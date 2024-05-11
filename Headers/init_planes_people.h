//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_INIT_PLANES_PEOPLE_H
#define PROJETO_2_INIT_PLANES_PEOPLE_H

#include "structs.h"
#include <iostream>
#include "Aux_functions.h"
void init_home_passengers(Plane &plane , file_data &fileData, int num_of_passengers = 0);
void init_passengers(Plane &plane, file_data &fileData,int num_of_passengers = 0);
void init_plane(Airport &airport, file_data &fileData);

Airport init_airport(file_data fileData);
void populate_nacionalityList(Airport &airport, file_data fileData);

#endif //PROJETO_2_INIT_PLANES_PEOPLE_H

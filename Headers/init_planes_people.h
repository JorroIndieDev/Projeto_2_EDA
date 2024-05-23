//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_INIT_PLANES_PEOPLE_H
#define PROJETO_2_INIT_PLANES_PEOPLE_H

#include "structs.h"
#include <iostream>
#include "Aux_functions.h"
/**
 * Inicializa os passageiros do aviao e adiciona-os à lista de passageiros do aviao
 * @param plane - Referência para o objeto Plane, onde os passageiros serao adicionados no aviao
 * @param fileData - Referência para o objeto file_data
 * @param num_of_passengers - Numero de passageiros a serem incializados
 */
void init_home_passengers(Plane &plane , file_data &fileData, int num_of_passengers = 0);
/** Inicializa passageiros no avião passado como parâmetro com todas as suas caraterísticas a partir
 *  do file_data também ele passado no parâmetro.
 *
 * @param plane - Referência para o objeto Plane, onde os passageiros serao adicionados no aviao
 * @param fileData - Referência para o objeto file_data
 * @param num_of_passengers - Número de passageiros passado quando a função é chamada
 * */
void init_passengers(Plane &plane, file_data &fileData,int num_of_passengers = 0);
/**
 * Inicializa um novo avião, com as informaçoes contidas no fileData, e adiciona-o à lista de chegadas do aeroporto.
 * @param airport - Referência para o objeto Airport
 * @param fileData - Referência para o objeto file_data
 */
void init_plane(Airport &airport, file_data &fileData);
/**
 * Inicializa o airport com valores nulos e inicializa os tamanhos dos arrays associados.
 * @param fileData - Referência para o objeto file_data
 */
Airport init_airport(file_data fileData);
/**
 * Popula a lista de nacionalidades do aeroporto com base nos dados fornecidos pelo arquivo, exceto nacionalidade portuguesa
 * @param airport - Referência para o objeto Airport
 * @param fileData - Referência para o objeto file_data
 */
void populate_nacionalityList(Airport &airport, file_data fileData);

#endif //PROJETO_2_INIT_PLANES_PEOPLE_H

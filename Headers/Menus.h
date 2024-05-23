//
// Created by goliv on 4/17/2024.
//
#ifndef PROJETO_2_MENUS_H
#define PROJETO_2_MENUS_H

#include "structs.h"
#include "Aux_functions.h"
/**
 * Simula um ciclo diário de um aeroporto, mostrando todos os aviões na chegada, pista e a descolar.
 * @param airport - Referência para o objeto Airport
 * @param fileData - Objeto contendo todas as informações relacionadas aos arquivos do airport
 */
void dayCycle(Airport &airport, file_data fileData);
/** Age como o menu de diferentes opções que o usuário pode escolher para interagir com o
 * programa, sendo que pode escolher respetivamente:
 *  -Visualizar os passageiros na rampa;
 *  -Apresentar árvore de passageiros ordenada do ponto de vista do utilizador;
 *  -Procurar os passageiros quer nas chegadas, quer nas saídas pelo seu nome;
 *  -Editar a nacionalidade de um passageiro num avião que esteja a chegar;
 *  -Inverter a prioridade dos aviões que se encontram na rampa;
 *  -Voltar ao menu principal;
 *
 * @param airport - passa um parâmetro do tipo Airport para poder manipulá-lo e percorrê-lo
 * @param fileData - Objeto contendo todas as informações relacionadas aos arquivos do airport
 * */
void option(Airport &airport , file_data &fileData);
#endif //PROJETO_2_MENUS_H

//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AIRPORTLISTHANDLER_H
#define PROJETO_2_AIRPORTLISTHANDLER_H

#include "structs.h"
#include "Aux_functions.h"
#include <iostream>



// List Logs

/** Feito por: Joao Oliveira \n
 * Imprime os aviões que se encontram na lista ligada passada como parâmetro, assim
 * imprime-os com as suas diferentes caraterísticas respetivamente:
 *      -Avião;
 *      -Modelo;
 *      -Origem;
 *      -Destino;
 *
 * @param list - passa uma lista ligada para poder manipulá-la e percorrê-la
 * */
void log_planes(llnode * list);

/** Feito por: Joao Oliveira \n
 * Imprime os passageiros que se encontram no avião que foi passado como parâmetro
 *
 * @param plane - passa um parâmetro do tipo Plane para poder manipulá-lo e percorrê-lo
 * */
void log_passengers_in_plane(Plane plane);

/** Feito por: Joao Sa\n
 * Exibe as informações de um passageiro.
 * @param passageiro -  Ponteiro para um passageiro
 */
void log_passenger(passenger *passageiro);


// List Functions ADD

/** Feito por: Joao Oliveira\n
 * Adiciona o primeiro avião da lista de partidas do aeroporto
 * @param airport - Referência para o objeto Airport
 * @param plane -  Referência para o objeto Plane que representa o avião a ser adicionado à lista de chegadas
 */
void add_arriving_plane(Airport &airport, Plane &plane);

/** Feito por: Joao Oliveira\n
 * Move o primeiro avião da lista da rampa para a  lista de partidas do aeroporto
 * @param airport - Referência para o objeto Airport
 * @param fileData -  Referência para o objeto file_data
 */
void add_departing_plane(Airport &airport, file_data &fileData);

/** Feito por: Joao Oliveira\n
 * Move o primeiro avião da lista de chegada para a  lista da rampa do aeroporto
 * @param airport - Referência para o objeto Airport
 * @param fileData -  Referência para o objeto file_data
 */
void add_ramp_plane(Airport &airport, file_data &fileData);

/** Joao Oliveira \n
 * Adiciona os passageiros ao avião
 *
 * @param airport - passa um parâmetro do tipo Airport para poder manipulá-lo e percorrê-lo
 * @param fileData - ficheiro de dados que permite guardar informações
 * @param plane - passa um parâmetro do tipo Plane para poder manipulá-lo e percorrê-lo
 * */
void add_passengers(Airport &airport, Plane &plane, file_data &fileData);

// List Functions Remove

/** Feito por: Joao Oliveira\n
 * Remove o primeiro avião da lista de partidas do aeroporto
 * @param airport - Referência para o objeto Airport
 */
void remove_departing_plane(Airport &airport);


// the rest of List Functions

/** Feito por: Joao Sa\n
 * Inverte a ordem dos aviões na rampa
 * * @param airport - Referência para o objeto Airport
 */
void reverse_ramp(Airport &airport);

/** Feito por: Joao Oliveira, Vanderlan \n
 * Irá pedir ao utilizador para fornecer o primeiro e último nome de um passageiro e percorrerá
 *  a lista passada como parâmetro para encontrá-lo.
 *
 * @param list - Lista ligada a ser percorrida
 * */
passenger * search_passengers(llnode *list);

// tree handler functions

/** Feito por: Joao Oliveira\n
 * Cria e inicializa um novo nodo para uma árvore de passageiros, associada a uma nacionalidade específica.
 * @param passageiro -  Referencia para um passageiro
 */
Nacionality::Pass_tree * new_tree_node(struct passenger &passenger);

/** Feito por: Joao Oliveira\n
 * Insere um novo passageiro na árvore de passageiros associada a uma nacionalidade específica.
 * @param tree_node - Ponteiro para a raiz da arvore onde sera inserido o passageiro
 * @param passageiro -  Referencia para um passageiro
 */
Nacionality::Pass_tree * insert_tree_node(Nacionality::Pass_tree * tree_node, struct passenger &passenger);

/** Feito por: Joao Oliveira\n
 * Imprime os nós de uma árvore de passageiros em ordem decrescente de nível, da direita para a esquerda.
 * @param root - Ponteiro para a raiz da arvore
 * @param level -  Nivel atual do nodo na arvore
 */
void print_tree_leftrigt(Nacionality::Pass_tree* root, int space);

/** Feito por: Joao Oliveira, Vanderlan\n
 * Remove um passageiro na árvore de passageiros associada a uma nacionalidade específica.
 * @param tree_node - Ponteiro para a raiz da arvore onde sera inserido o passageiro
 * @param passageiro -  Referencia para um passageiro
 */
Nacionality::Pass_tree * delete_node(Nacionality::Pass_tree * root, std::string name);

/** Feito por: Joao Oliveira\n
 * Procura um passageiro na arvore de passageiros, através do primeiro nome, e retorna um endereço do passageiro
 * se encontrado
 * @param tree_node - Ponteiro para a raiz da arvore onde sera inserido o passageiro
 * @param passageiro -  Referencia para um passageiro
 */
Nacionality::Pass_tree * search_namesTree(Nacionality::Pass_tree * root,std::string name);

/** Feito por: Joao Oliveira, Vanderlan\n
 * Function to balance the a tree of Nacionality::Pass_tree based on DSW algorithm
 * @param root - root of the tree type of Nacionality::Pass_tree *
 * @return  the new balanced tree
 */
Nacionality::Pass_tree * balance_tree(Nacionality::Pass_tree * root);

/** Feito por:Joao Oliveira\n
 * Auxiliary fuction for balance_tree
 * @param root root of the tree being balanced
 * @param num_of_nodes "level" of the tree root being 0
 */
void compressTree(Nacionality::Pass_tree * root, int num_of_nodes);

/** Feito por: Joao Oliveira\n
 * Auxiliary function for balance_tree makes the "backbone" for the DSW algorithm
 * @param root root of the tree being balacned
 * @return  number of rotations it took to make the "backbone"
 */
int make_spine(Nacionality::Pass_tree  * root);

/** Feito por: Joao Sa \n
 * Imprime uma árvore passada como parâmetro utilizando o método Travessia Infixa que
 *  irá imprimi-la a partir da esquerda para a direita
 *
 * @param nacionality - passa um parâmetro de árvore binária de nacionalidades
 * */
void travessiaInfixa(Nacionality::Pass_tree *nacionality);

/** Feito por: Vanderlan, Joao Oliveira \n
 * Pede ao usuário o avião que está em emergência e, de seguida, vai percorrer a lista de aviões
 *  que está a chegar para aterrá-lo e colocá-lo na rampa se possível. Se a rampa estiver cheia,
 *  algum avião irá descolar para dar lugar.
 *
 * @param airport - Referência para o objeto Airport
 * @param fileData -  Referência para o objeto file_data
 * */
void emergency_handler(Airport * airport,file_data &fileData);

// Aditional functions that work with the airport in general accounting for tree and lists

/** Feito por: grupo. \n
 * Irá comparar a nacionalidade dos passageiros a chegar com a nacionalidade definida dentro da
 *  função. Se esta for diferente então os passageiros serão introduzidos numa árvore binária onde
 *  cada nodo é uma nacionalidade diferente.
 *
 * @param airport - Referência para o objeto airport
 * */
void arriving_foreigners(Airport &airport , Plane & plane);

/** Feito por: grupo. \n
 * Irá pedir ao utilizador para fornecer o primeiro e último nome de um passageiro, irá encontrá-lo
 *  após percorrer o aeroporto e mudar a sua nacionalidade atual para aquela passada como parâmetro
 *
 * @param newNationality - Nova nacionalidade a ser introduzida
 * @param airport - Referência para o objeto airport
 * */
void change_nacionality(std::string newNationality, Airport &airport);


#endif //PROJETO_2_AIRPORTLISTHANDLER_H

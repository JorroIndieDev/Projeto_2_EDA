//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AUX_FUNCTIONS_H
#define PROJETO_2_AUX_FUNCTIONS_H
#include <iostream>
#include "structs.h"

/**
 * File structure to keep the data in memory for the process of the program
 */
struct file_data{

    const std::string Ticket = "TK.";
    long ticket_number = 1000000000;

    std::string * destino;
    std::string * modelo;
    std::string * nacionalidade;
    std::string * origem;
    std::string * primeiro_nome;
    std::string * segundo_nome;
    std::string * voo;

    int current_index_name;
    int destino_size;
    int modelo_size;
    int nacionalidade_size;
    int origem_size;
    int primeiro_nome_size;
    int segundo_nome_size;
    int voo_size;

    file_data(){
        destino = nullptr;
        modelo = nullptr;
        nacionalidade = nullptr;
        primeiro_nome = nullptr;
        segundo_nome = nullptr;
        voo = nullptr;

        destino_size = 0;
        modelo_size = 0;
        nacionalidade_size = 0;
        origem_size = 0;
        primeiro_nome_size = 0;
        segundo_nome_size = 0;
        voo_size = 0;
    }

};

/**
 * Function loads the files from Data_Files, which are necessary for the function of the airport, these files contain
 * the information of planes and passangers
 *
 * @param fileData - array for the data that needs to be used to create passangers and planes
 * */
void load_files_to_mem(file_data &fileData);

/**
 * Lê o conteúdo de um arquivo de texto e armazena num array de strings. O tamanho desse array é determinado pelo
 * parametro size
 * @param file_name - O nome do arquivo a ser lido sem extencao
 * @param size - O tamanho do array de string a ser criado
 */
std::string* read_files(std::string file_name,int size);

/**
 * Conta o numero de linhas de um determinado arquivo de texto, especificado pelo parametro file_name
 * @param file_name - O nome do arquivo a ser lido.
 */
int count_lines(std::string file_name);

/** Gera números de forma aleatória dentro do alcance especificado pelo utilizador
 *
 * @param lower - Alcance mínimo especificado
 * @param upper - Alcance máximo especificado
 **/
int random_range(int lower, int upper);

/** Lê o ficheiro de nome file_name e verifica se encontrou o ficheiro, então vai ler as
 * informações da struct aeroporto e carregar as suas informações para o ficheiro de nome
 * passado pelo utilizador como parâmetro
 *
 * @param airport - passa um parâmetro do tipo Airport para poder manipulá-lo e percorrê-lo
 * @param file_name - nome do ficheiro a passar para a função
 * @param fileData - array for the data that needs to be used to create passangers and planes
 * */
void SaveToFile(std::string file_name, Airport * airport, file_data  &fileData);

/**
 * Lê o ficheiro de nome file_name e verifica se encontrou o ficheiro, então vai lê-lo
 * e carregar as suas informações para a struct aeroporto
 *
 * @param file_name
 * @param airport
 * @param fileData - array for the data that needs to be used to create passangers and planes
 */
void LoadFromFile(std::string file_name, Airport & Oairport,file_data &fileData);

/**
 * Function is an Auxiliary function to SaveToFile it saves the tree of type Nacionality::Pass_tree
 * @param root root of the tree to be saved
 * @param outfile file to be written to
 */
void Serialized_tree(Nacionality::Pass_tree *root, std::ofstream &outfile);

/**
 * Function is an Auxiliary function to LoadFromFile it Loads the tree of type Nacionality::Pass_tree
 * @param root root of the tree to be saved
 * @param n number of passengers in the tree
 * @param infile file to be read
 * @return returns the root of a tree built from the contents of infile
 */
Nacionality::Pass_tree * DeSerialized_travessiaInfixa(int &n, Nacionality::Pass_tree *root, std::ifstream &infile);

/**
 * Organiza uma lista de strings por ordem alfabetica, atraves do algoritmo de ordenaçao (selection sort).
 * @param list - Array de string
 * @param list_size - O tamanho do array
 */
void listSort(std::string list[], int list_size);

#endif //PROJETO_2_AUX_FUNCTIONS_H

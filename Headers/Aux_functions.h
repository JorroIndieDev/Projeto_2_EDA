//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AUX_FUNCTIONS_H
#define PROJETO_2_AUX_FUNCTIONS_H
#include <iostream>
#include "structs.h"

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

// reads and loads all the files to memory
void load_files_to_mem(file_data &fileData);
// read file and return sring array
std::string* read_files(std::string file_name,int size);
// count number of lines in the file
int count_lines(std::string file_name);
// random num
int random_range(int lower, int upper);
// max value between two
int max(int a,int b);


void SaveToFile(std::string file_name, Airport * airport, file_data  &fileData);
void LoadFromFile(std::string file_name, Airport & Oairport,file_data &fileData);

void Serialized_travessiaInfixa(Nacionality::Pass_tree *root, std::ofstream &outfile);
Nacionality::Pass_tree * DeSerialized_travessiaInfixa(int &n, Nacionality::Pass_tree *root, std::ifstream &infile,int &lineNumTemp);

#endif //PROJETO_2_AUX_FUNCTIONS_H

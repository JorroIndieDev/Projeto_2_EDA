//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AUX_FUNCTIONS_H
#define PROJETO_2_AUX_FUNCTIONS_H
#include <iostream>
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

    int destino_size;
    int modelo_size;
    int nacionalidade_size;
    int origem_size;
    int primeiro_nome_size;
    int segundo_nome_size;
    int voo_size;
};

// reads and loads all the files to memory
void load_files_to_mem(file_data &fileData);
// read file and return sring array
std::string* read_files(std::string file_name,int size);
// count number of lines in the file
int count_lines(std::string file_name);
// save to binary documents
void saveToFile(const file_data& data, const std::string& filename);
// load binary docs
void loadFromFile(file_data& data, const std::string& filename);
// random num
int random_range(int lower, int upper);
#endif //PROJETO_2_AUX_FUNCTIONS_H

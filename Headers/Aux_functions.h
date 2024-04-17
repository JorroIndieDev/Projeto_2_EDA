//
// Created by goliv on 4/17/2024.
//

#ifndef PROJETO_2_AUX_FUNCTIONS_H
#define PROJETO_2_AUX_FUNCTIONS_H
#include <iostream>
struct file_data{
    std::string * destino;
    std::string * modelo;
    std::string * nacionalidade;
    std::string * origem;
    std::string * primeiro_nome;
    std::string * segundo_nome;
    std::string * voo;
};

// read file and return sring array
std::string* read_files(std::string file_name);
// count number of lines in the file
int count_lines(std::string file_name);
// save to binary documents
void saveToFile(const file_data& data, const std::string& filename);
// load binary docs
void loadFromFile(file_data& data, const std::string& filename);
#endif //PROJETO_2_AUX_FUNCTIONS_H

//
// Created by goliv on 4/17/2024.
//

#include "Headers/Aux_functions.h"

#include <fstream>

void load_files_to_mem(file_data &fileData){

    fileData.destino_size = count_lines("../Data_Files/destino.txt");
    fileData.modelo_size = count_lines("../Data_Files/modelo.txt");
    fileData.nacionalidade_size = count_lines("../Data_Files/nacionalidade.txt");
    fileData.origem_size = count_lines("../Data_Files/origem.txt");
    fileData.primeiro_nome_size = count_lines("../Data_Files/primeiro_nome.txt");
    fileData.segundo_nome_size = count_lines("../Data_Files/segundo_nome.txt");
    fileData.voo_size = count_lines("../Data_Files/voo.txt");

    fileData.destino = read_files("../Data_Files/destino.txt", fileData.destino_size);
    fileData.modelo = read_files("../Data_Files/modelo.txt", fileData.modelo_size);
    fileData.nacionalidade = read_files("../Data_Files/nacionalidade.txt", fileData.nacionalidade_size);
    fileData.origem = read_files("../Data_Files/origem.txt", fileData.origem_size);
    fileData.primeiro_nome = read_files("../Data_Files/primeiro_nome.txt", fileData.primeiro_nome_size);
    fileData.segundo_nome = read_files("../Data_Files/segundo_nome.txt", fileData.segundo_nome_size);
    fileData.voo = read_files("../Data_Files/voo.txt", fileData.voo_size);

}

std::string* read_files(std::string file_name, int size){
    std::ifstream file;
    file.open(file_name);
    std::string * string_arr = new std::string[size];
    int i = 0;
    std::string line;
    while(file >> line){
        string_arr[i] = line;
        i++;
    }
    return string_arr;
}

int count_lines(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    int i = 0;
    std::string line;
    while(file >> line){
        i++;
    }
    return i;
}

int random_range(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
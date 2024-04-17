//
// Created by goliv on 4/17/2024.
//

#include "Headers/Aux_functions.h"

#include <fstream>


std::string* read_files(std::string file_name){
    std::ifstream file;
    file.open(file_name);
    std::string * string_arr = new std::string[count_lines(file_name)];
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

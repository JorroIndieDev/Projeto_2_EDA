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

struct customer {
    char  fname[20],lname[20];
    int   acct_num;
    float acct_balance;
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


void SaveToFile(std::string file_name, Airport * airport);
void SaveToFile(std::string file_name, file_data * fileData);
void LoadFromFile(std::string file_name, Airport & Oairport,file_data fileData);
void LoadFromFile(std::string file_name, file_data * fileData);


// Functions to serialize data:
void serialize_llnode(int listSize,llnode *list, std::ofstream &outfile);
void serialize_Nationality(int listSize, Nacionality * nacionality, std::ofstream &outfile);
void serialize_tree(Nacionality::Pass_tree * root, std::ofstream &outfile);

// Functions to deserialize data:
void deserialize_llnode(llnode *&list ,std::ifstream &infile);
void deserialize_Nationality(Nacionality*&nacionality,std::ifstream &infile);
void deserialize_tree(Nacionality::Pass_tree *&root,std::ifstream &infile);

void Serialized_travessiaInfixa(Nacionality::Pass_tree *root, std::ofstream &outfile);
void DeSerialized_travessiaInfixa(int &n, Nacionality::Pass_tree *root, std::ifstream &infile);

#endif //PROJETO_2_AUX_FUNCTIONS_H

//
// Created by goliv on 4/17/2024.
//

#include "Headers/Aux_functions.h"

#include <fstream>
#include "stdlib.h"

void load_files_to_mem(file_data &fileData){

    // assigns the size of the arrays for the loading of the Data
    fileData.modelo_size = count_lines("../Data_Files/modelo.txt");
    fileData.nacionalidade_size = count_lines("../Data_Files/nacionalidade.txt");
    fileData.primeiro_nome_size = count_lines("../Data_Files/primeiro_nome.txt");
    fileData.segundo_nome_size = count_lines("../Data_Files/segundo_nome.txt");
    fileData.voo_size = count_lines("../Data_Files/voo.txt");

    // loads the Data files provided to memory so it can be freely used and not request aditional mem during runtime
    fileData.modelo = read_files("../Data_Files/modelo.txt", fileData.modelo_size);
    fileData.nacionalidade = read_files("../Data_Files/nacionalidade.txt", fileData.nacionalidade_size);
    fileData.primeiro_nome = read_files("../Data_Files/primeiro_nome.txt", fileData.primeiro_nome_size);
    fileData.segundo_nome = read_files("../Data_Files/segundo_nome.txt", fileData.segundo_nome_size);
    fileData.voo = read_files("../Data_Files/voo.txt", fileData.voo_size);

    // loads the same divided seperatly duo to being differnt types of file (longer lines)
    fileData.origem_size = count_lines("../Data_Files/origem.txt");
    fileData.origem = read_files("../Data_Files/origem.txt", fileData.origem_size);
    fileData.destino_size = count_lines("../Data_Files/destino.txt");
    fileData.destino = read_files("../Data_Files/destino.txt", fileData.destino_size);

}

std::string * read_files(std::string file_name, int size){

    // create var file to aux read
    std::ifstream file;

    // opens file specified
    file.open(file_name);

    // creates the new array to be returned set size passed by the size @param
    std::string * string_arr = new std::string[size];

    // init index to access array
    int index = 0;

    // aux var to get the line of the file
    std::string line;

    // loop until file is eof and attribute each line to array
    while(std::getline(file,line)){
        string_arr[index] = line;
        index++;
    }

    // return the array
    return string_arr;
}

int count_lines(std::string file_name){

    // create var file to aux read
    std::ifstream file;

    // opens file specified
    file.open(file_name);

    // init number of lines
    int num_of_lines = 0;

    // aux var to get the line of the file
    std::string line;

    // loop until file is eof and increment num_of_lines
    while(std::getline(file,line)){
        num_of_lines++;
    }

    // return the number of lines in each file
    return num_of_lines;
}

int random_range(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void SaveToFile(std::string file_name, Airport &airport) {

    // initialize the file with fstream
    std::ofstream outfile;

    // auxiliary var to not destroy original
    struct Airport input = airport;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".dat";
    FILE_PATH += file_name;

    //open file
    outfile.open(FILE_PATH); // by using FILE_PATH we ensure that the file is always oppened from the right dir


    // if file is not valid cerr out and quit
    if (!outfile.is_open()) {
        std::cerr << "\nFile -> { " << file_name << " } Not found\n\n";
        outfile.close();
        outfile.clear();
        exit(1);
    }

    // write struct to file and close
    outfile.write(reinterpret_cast <char *> (&input), sizeof(struct Airport));
    outfile.close();
    outfile.clear();

}

void LoadFromFile(std::string file_name, Airport &airport){

    // initialize the file with fstream
    std::ifstream infile;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".dat";
    FILE_PATH += file_name;

    // open file
    infile.open(FILE_PATH); // by using FILE_PATH we ensure that the file is always oppened from the right dir

    // if file is not valid cerr out and quit
    if (!infile.is_open()) {
        std::cerr << "\nFile -> { " << file_name << " } Not found\n\n";
        infile.close();
        infile.clear();
        exit(1);
    }
    // read struct from file and close
    infile.read(reinterpret_cast <char *> (&airport), sizeof(struct Airport));
    infile.close();
    infile.clear();
}

int max(int a, int b){
    return (a < b) ? a : b;
}
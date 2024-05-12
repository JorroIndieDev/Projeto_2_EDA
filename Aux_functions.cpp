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

void SaveToFile(std::string file_name, Airport * airport) {

    // initialize the file with fstream
    std::ofstream outfile;

    // auxiliary var to not destroy original
    Airport * input = airport;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".txt";
    FILE_PATH += file_name;

    // open file
    outfile.open(FILE_PATH); // by using FILE_PATH we ensure that the file is always oppened from the right dir


    // if file is not valid cerr out and quit
    if (!outfile.is_open()) {
        std::cerr << "\nFile -> { " << file_name << " } Not found\n\n";
        outfile.close();
        outfile.clear();
        exit(1);
    }

    // write struct to file and close

    outfile << airport->arrival_cap << " " << airport->ramp_cap << " " << airport->depart_cap << "\n";
    outfile << airport->emergency_state << " " << airport->closed << " " << airport->cycles_closed << "\n";


    // size of Arrival List
    outfile << airport->num_in_arrival << "\n";

    llnode * auxArr = airport->head_arrv;

    // write each node
    while (auxArr != NULL){

        // write the contents of the plane
        Plane plane = auxArr->plane;
        outfile << plane.flight_name << " "
                << plane.model << " "
                << plane.origin << " "
                << plane.destination << " "
                << plane.capacity << "\n";

        // write the passengers in the plane
        Plane::passenger_in_plane * tempPass = plane.head_passenger;
        while (tempPass != NULL){

            // write the contents for each passenger
            passenger auxPass = tempPass->passenger;
            outfile << auxPass.nacionality << " "
                    << auxPass.first_name << " "
                    << auxPass.second_name << " "
                    << auxPass.ticket_num << "\n";

            tempPass = tempPass->next_passenger;
        }

        auxArr = auxArr->next;
    }

    // size of Ramp List
    outfile << airport->num_in_ramp << "\n";

    llnode * auxRamp = airport->head_ramp;

    // write each node
    while (auxRamp != NULL){

        // write the contents of the plane
        Plane plane = auxRamp->plane;
        outfile << plane.flight_name << " "
                << plane.model << " "
                << plane.origin << " "
                << plane.destination << " "
                << plane.capacity << "\n";

        // write the passengers in the plane
        Plane::passenger_in_plane * tempPass = plane.head_passenger;
        while (tempPass != NULL){

            // write the contents for each passenger
            passenger auxPass = tempPass->passenger;
            outfile << auxPass.nacionality << " "
                    << auxPass.first_name << " "
                    << auxPass.second_name << " "
                    << auxPass.ticket_num << "\n";

            tempPass = tempPass->next_passenger;
        }

        auxRamp = auxRamp->next;
    }

    // size of Departure List
    outfile << airport->num_in_depart << "\n";

    llnode * auxDep = airport->head_dep;

    // write each node
    while (auxDep != NULL){

        // write the contents of the plane
        Plane plane = auxDep->plane;
        outfile << plane.flight_name << " "
                << plane.model << " "
                << plane.origin << " "
                << plane.destination << " "
                << plane.capacity << "\n";

        // write the passengers in the plane
        Plane::passenger_in_plane * tempPass = plane.head_passenger;
        while (tempPass != NULL){

            // write the contents for each passenger
            passenger auxPass = tempPass->passenger;
            outfile << auxPass.nacionality << " "
                    << auxPass.first_name << " "
                    << auxPass.second_name << " "
                    << auxPass.ticket_num << "\n";

            tempPass = tempPass->next_passenger;
        }

        auxDep = auxDep->next;
    }

    // size of Nationality List
    outfile << airport->nacionality_size << "\n";

    Nacionality * auxll = airport->nacionality_head;

    // write each node
    while (auxll != NULL){

        // write nationality
        outfile << auxll->nacionality << "\n";
        // write tree
        Serialized_travessiaInfixa(auxll->root_passenger,outfile);
        auxll = auxll->next_nacionality;
    }

    outfile.close();
    outfile.clear();
}

void Serialized_travessiaInfixa(Nacionality::Pass_tree *root, std::ofstream &outfile) {
    if (root == nullptr) return;
    Serialized_travessiaInfixa(root->left,outfile);
    outfile << root->passenger.nacionality << " "
            << root->passenger.first_name << " "
            << root->passenger.second_name << " "
            << root->passenger.ticket_num << "\n";
    Serialized_travessiaInfixa(root->right,outfile);
}

/*void serialize_llnode(int listSize, llnode * list, std::ofstream &outfile) {

    size_t num_llnodes = listSize;
    outfile.write(reinterpret_cast<const char*>(&num_llnodes), sizeof(size_t));

    llnode *tempList = list;

    // Write nodes
    while (tempList != nullptr) {
        Plane plane = tempList->plane;

        // Write plane data
        outfile.write(reinterpret_cast<const char*>(&plane), sizeof(Plane));

        // Write passenger data for the plane
        Plane::passenger_in_plane *tempPassengerList = plane.head_passenger;
        while (tempPassengerList != nullptr) {
            passenger tempPass = tempPassengerList->passenger;
            outfile.write(reinterpret_cast<const char*>(&tempPass), sizeof(passenger));
            tempPassengerList = tempPassengerList->next_passenger;
        }

        tempList = tempList->next;
    }
}

void serialize_tree(Nacionality::Pass_tree * root, std::ofstream &outfile){
    bool hasRoot = (root != nullptr);
    outfile.write(reinterpret_cast<const char*>(&hasRoot), sizeof(bool));

    if (hasRoot) {
        outfile.write(reinterpret_cast<const char *>(root), sizeof(root));

        serialize_tree(root->left, outfile);
        serialize_tree(root->right, outfile);
    }else return;
}

void serialize_Nationality(int listSize,Nacionality * nacionality, std::ofstream &outfile){

    size_t num_llnodes = listSize;
    outfile.write(reinterpret_cast<const char*>(&num_llnodes), sizeof(size_t));

    Nacionality *tempList = nacionality;

    // Write nodes
    while (tempList != nullptr) {

        outfile.write(reinterpret_cast<const char*>(nacionality),sizeof(nacionality));

        serialize_tree(nacionality->root_passenger,outfile);

        tempList = tempList->next_nacionality;
    }
}*/


void LoadFromFile(std::string file_name, Airport * airport){

    // initialize the file with fstream
    std::ifstream infile;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".txt";
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

    infile.close();
    infile.clear();
}

/*
void deserialize_llnode(llnode *&list ,std::ifstream &infile) {

    size_t num_llnodes;
    infile.read(reinterpret_cast<char*>(&num_llnodes), sizeof(size_t));

    llnode *tempList = new llnode;
    tempList->next = nullptr;
    llnode *auxList = tempList;

    for (size_t i = 0; i < num_llnodes; ++i) {
        auxList->next = new llnode;  // Create a new node for the next plane
        auxList = auxList->next;      // Move to the newly created node

        infile.read(reinterpret_cast<char*>(&auxList->plane), sizeof(Plane));

        // Initialize head_passenger for the current plane
        auxList->plane.head_passenger = new Plane::passenger_in_plane;
        Plane::passenger_in_plane *tempPassengerList = auxList->plane.head_passenger;

        for (int j = 0; j < auxList->plane.capacity; ++j) {
            tempPassengerList->next_passenger = new Plane::passenger_in_plane;  // Create a new passenger node
            tempPassengerList = tempPassengerList->next_passenger;              // Move to the newly created node

            passenger tempPass;
            infile.read(reinterpret_cast<char*>(&tempPass), sizeof(passenger));

            // Assign passenger data to the current node
            tempPassengerList->passenger = tempPass;
        }
    }

// After the loop, the last node's next should be nullptr
    auxList->next = nullptr;

   size_t num_llnodes;
    infile.read(reinterpret_cast<char*>(&num_llnodes), sizeof(size_t));

    llnode * tempList = new llnode;
    tempList->next = nullptr;
    llnode * auxList = tempList;

    for (int i = 0; i < num_llnodes; ++i) {
        auxList->next = nullptr;

        infile.read(reinterpret_cast<char*>(&auxList->plane), sizeof(Plane));

        auxList->plane.head_passenger = new Plane::passenger_in_plane;

        Plane::passenger_in_plane *tempPassengerList = auxList->plane.head_passenger;
        for (int j = 0; j < auxList->plane.capacity; ++j) {
            tempPassengerList->next_passenger = nullptr;
            passenger tempPass;
            infile.read(reinterpret_cast<char*>(&tempPass), sizeof(passenger));
            tempPassengerList->passenger = tempPass;
            tempPassengerList = tempPassengerList->next_passenger;
        }

        auxList = auxList->next;
//    }

    if(list != nullptr){
        list = nullptr;
        list = tempList;
    }else{
        list = tempList;
    }
}

void deserialize_tree(Nacionality::Pass_tree *&root,std::ifstream &infile){
    if (root == NULL)return;

    infile.read(reinterpret_cast<char*>(root),sizeof(root));

    deserialize_tree(root->right,infile);
    deserialize_tree(root->left,infile);
}

void deserialize_Nationality(Nacionality *&nacionality,std::ifstream &infile){

    Nacionality *tempList = nacionality;

    // Write nodes
    while (tempList != nullptr) {

        infile.read(reinterpret_cast<char*>(nacionality),sizeof(nacionality));

        deserialize_tree(nacionality->root_passenger,infile);

        tempList = tempList->next_nacionality;
    }
}
*/

void SaveToFile(std::string file_name, file_data &fileData) {

    // initialize the file with fstream
    std::ofstream outfile;

    // auxiliary var to not destroy original
    struct file_data input = fileData;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".txt";
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



    outfile.close();
    outfile.clear();

}

void LoadFromFile(std::string file_name, file_data &fileData){

    // initialize the file with fstream
    std::ifstream infile;

    // adding file to the file PATH where airport data is stored
    std::string FILE_PATH = "../AirportData/";

    // ensure the file is .dat
    file_name += ".txt";
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
    infile.read(reinterpret_cast <char *> (&fileData), sizeof(struct file_data));

    infile.close();
    infile.clear();
}

int max(int a, int b){
    return (a < b) ? a : b;
}
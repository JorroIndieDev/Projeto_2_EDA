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

    infile >> airport->arrival_cap >> airport->ramp_cap >> airport->depart_cap;
    infile >> airport->emergency_state >> airport->closed>> airport->cycles_closed;


    // size of Arrival List
    infile >> airport->num_in_arrival;

    llnode * auxArr = airport->head_arrv;

    // read each node
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

int max(int a, int b){
    return (a < b) ? a : b;
}
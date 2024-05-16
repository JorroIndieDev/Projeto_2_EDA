//
// Created by goliv on 4/17/2024.
//

#include "Headers/Aux_functions.h"
#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"
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
        outfile << plane.flight_name << "\n"
                << plane.model << "\n"
                << plane.origin << "\n"
                << plane.destination << "\n"
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
        outfile << plane.flight_name << "\n"
                << plane.model << "\n"
                << plane.origin << "\n"
                << plane.destination << "\n"
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
        outfile << plane.flight_name << "\n"
                << plane.model << "\n"
                << plane.origin << "\n"
                << plane.destination << "\n"
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
        int n_passangers = 0;

        // write nationality
        outfile << auxll->nacionality << "\n";
        // write tree
        outfile << auxll->num_of_pass_in_tree << "\n";
        Serialized_travessiaInfixa(auxll->root_passenger,outfile);
        outfile << "skip\n";
        auxll = auxll->next_nacionality;
    }

    outfile.close();
    outfile.clear();
}

void Serialized_travessiaInfixa(Nacionality::Pass_tree *root, std::ofstream &outfile) {
    if (root == nullptr) return;
    outfile << root->passenger.nacionality << " "
            << root->passenger.first_name << " "
            << root->passenger.second_name << " "
            << root->passenger.ticket_num << "\n";
    Serialized_travessiaInfixa(root->left,outfile);
    Serialized_travessiaInfixa(root->right,outfile);
}
void DeSerialized_travessiaInfixa(int &n, Nacionality::Pass_tree *root, std::ifstream &infile) {
    if (n == 0)return;
    std::string tempLine;
    std::string *temparr = new std::string[n];

    Nacionality::Pass_tree * tempTree = new Nacionality::Pass_tree;
    int x = 0;
    for (x; x < n; ++x) {
        std::getline(infile,tempLine);
        if (tempLine == "skip")break;
        temparr[x] = tempLine;
    }

    // separate string into array
    for (int i = 0; i < x; ++i) {
        std::string auxarr[4];
        int auxindex=0;
        for (int j = 0; j < temparr[i].size(); ++j) {
            if (temparr[i][j] == ' '){
                auxindex++;
                continue;
            }
            std::string aux;
            aux += temparr[i][j];
            auxarr[auxindex] = aux;
        }

        // treat the new array as sequential data for the passager struct
        passenger tempPass;
        tempPass.nacionality = auxarr[0];
        tempPass.first_name = auxarr[1];
        tempPass.second_name = auxarr[2];
        tempPass.ticket_num = auxarr[3];

        tempTree = insert_tree_node(tempTree,tempPass);
    }

    root = balance_tree(tempTree);

}
void LoadFromFile(std::string file_name, Airport & Oairport,file_data fileData){

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

    Airport airport = init_airport(fileData);

    // read struct from file and close

    infile >> airport.arrival_cap >> airport.ramp_cap >> airport.depart_cap;
    infile >> airport.emergency_state >> airport.closed>> airport.cycles_closed;


    // size of Arrival List
    infile >> airport.num_in_arrival;


    // read each node TODO Problems with accessing next nodes not properly added to the list
    for (int i = 0; i < airport.num_in_arrival; ++i) {
        llnode * auxArr = airport.head_arrv;

        char dump;
        infile >> dump;

        // write the contents of the plane
        Plane plane;
        std::getline(infile,plane.flight_name);
        plane.flight_name = dump + plane.flight_name;
        std::getline(infile,plane.model);
        std::getline(infile,plane.origin);
        std::getline(infile,plane.destination);
        infile >> plane.capacity;
        // write the passengers in the plane

        Plane::passenger_in_plane * tempPass = plane.head_passenger = NULL;
        for (int j = 0; j < plane.capacity; ++j) {

            // write the contents for each passenger
            passenger auxPass;
            infile >> auxPass.nacionality
                    >> auxPass.first_name
                    >> auxPass.second_name
                    >> auxPass.ticket_num;

            Plane::passenger_in_plane * aux = new Plane::passenger_in_plane;
            aux->next_passenger = nullptr;
            aux->passenger = auxPass;

            if (tempPass == NULL){
                tempPass = aux;
                tempPass->next_passenger = nullptr;
            }else{
                Plane::passenger_in_plane * tempAux = tempPass;
                while (tempAux != NULL){
                    tempAux = tempAux->next_passenger;
                }
                tempAux = aux;
                tempAux->next_passenger = nullptr;
            }

        }

        llnode * aux = new llnode;
        aux->plane = plane;
        aux->next = nullptr;

        if (auxArr == NULL){
            auxArr = aux;
            auxArr->next = nullptr;
        }else{
            llnode * auxLL = auxArr;
            while (auxLL != NULL){
                auxLL = auxLL->next;
            }
            auxLL = aux;
            auxLL->next = nullptr;
        }
    }

    // size of Ramp List
    infile >> airport.num_in_ramp;

    llnode * auxRamp = airport.head_ramp = new llnode;
    auxRamp->next = new llnode;

    // write each node
    for (int i = 0; i < airport.num_in_ramp; ++i) {

        // write the contents of the plane
        Plane plane;
        std::getline(infile,plane.flight_name);
        std::getline(infile,plane.model);
        std::getline(infile,plane.origin);
        std::getline(infile,plane.destination);
        infile >> plane.capacity;

        plane.head_passenger = nullptr;
        auxRamp->plane = plane;
        auxRamp = auxRamp->next;
        auxRamp->next = new llnode;
    }
    auxRamp = nullptr;

    // size of Departure List
    infile >> airport.num_in_depart;

    llnode * auxDep = airport.head_dep = new llnode;
    auxDep->next = new llnode;

    // write each node
    for (int i = 0; i < airport.num_in_depart; ++i) {

        // write the contents of the plane
        Plane plane;
        std::getline(infile,plane.flight_name);
        std::getline(infile,plane.model);
        std::getline(infile,plane.origin);
        std::getline(infile,plane.destination);
        infile >> plane.capacity;
        // write the passengers in the plane
        Plane::passenger_in_plane * tempPass = plane.head_passenger = new Plane::passenger_in_plane;
        tempPass->next_passenger = new Plane::passenger_in_plane;

        for (int j = 0; j < plane.capacity; ++j) {
            // write the contents for each passenger
            passenger auxPass;
            infile >> auxPass.nacionality
                   >> auxPass.first_name
                   >> auxPass.second_name
                   >> auxPass.ticket_num;

            tempPass->passenger = auxPass;
            tempPass = tempPass->next_passenger;
            tempPass->next_passenger = new Plane::passenger_in_plane;
        }
        auxDep->plane = plane;
        auxDep = auxDep->next;
        auxDep->next = new llnode;
    }
    auxDep = nullptr;

    // size of Nationality List
    infile >> airport.nacionality_size;

    Nacionality * auxll = airport.nacionality_head;

    // write each node
    while (auxll != NULL){
        std::string temp;
        // write nationality
        std::getline(infile,temp);
        if (temp == "skip"){
            infile >> auxll->nacionality;
        }else{
            auxll->nacionality = temp;
        }
        // write tree
        infile >> auxll->num_of_pass_in_tree;
        DeSerialized_travessiaInfixa(auxll->num_of_pass_in_tree,auxll->root_passenger,infile);
        auxll = auxll->next_nacionality;
    }

    infile.close();
    infile.clear();

    Oairport = airport;
}

int max(int a, int b){
    return (a < b) ? a : b;
}
#include <iostream>
#include "Headers/structs.h"
#include "Headers/AirportListHandler.h"
#include "Headers/Menus.h"
#include "Headers/init_planes_people.h"
#include "Headers/Aux_functions.h"
/*
 * NOTES:
 * (watch video explaining and leave notes here)
 *
 *
 */


int main() {

    Airport airport = init_airport();

    file_data fileData;
    fileData.destino = read_files("../Data_Files/destino.txt");
    fileData.modelo = read_files("../Data_Files/modelo.txt");
    fileData.nacionalidade = read_files("../Data_Files/nacionalidade.txt");
    fileData.origem = read_files("../Data_Files/origem.txt");
    fileData.primeiro_nome = read_files("../Data_Files/primeiro_nome.txt");
    fileData.segundo_nome = read_files("../Data_Files/segundo_nome.txt");
    fileData.voo = read_files("../Data_Files/voo.txt");

    dayCycle(airport);

    return 0;
}

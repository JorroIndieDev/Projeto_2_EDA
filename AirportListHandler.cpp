//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"
#include "Headers/init_planes_people.h"
#include <bits/stdc++.h>

void remove_departing_plane(Airport &airport) {
    if (airport.head_dep == NULL)return; // if head is NULL list is empty

    // since we parse  address we create a temp var to delete it afterward so that there is no memory leak
    llnode * temp = airport.head_dep;
    airport.head_dep = airport.head_dep->next;
    airport.num_in_depart--;

    // delete temp var
    delete temp;
}

void add_arriving_plane(Airport &airport, Plane &plane) {

    // create new Arrival node to add to list
    llnode * new_arrv = new llnode;
    new_arrv->plane = plane;
    new_arrv->next = nullptr;

    // if head NULL add at the head
    if (airport.head_arrv == NULL){
        airport.head_arrv = new_arrv;

    }else { // else add at the end
        llnode * ptr = airport.head_arrv;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_arrv;
        airport.num_in_arrival++;
    }
}

void add_departing_plane(Airport &airport, file_data &fileData) {
    if (airport.head_ramp == NULL)return;

    // remove from ramp
    llnode * temp = airport.head_ramp;
    airport.head_ramp = airport.head_ramp->next;
    airport.num_in_ramp--;

    // change destination and origin
    temp->plane.destination = fileData.destino[random_range(0,fileData.destino_size-1)];
    temp->plane.origin = "AeroportoEDA";

    // add to depart
    llnode * new_depart = new llnode;
    new_depart->plane = temp->plane;
    new_depart->next = nullptr;

    add_passengers(airport,new_depart->plane,fileData);

    if (airport.head_dep == NULL){
        airport.head_dep = new_depart;

    }else {
        llnode * ptr = airport.head_dep;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_depart;
        airport.num_in_depart++;
    }
    delete temp;
}

void add_passengers(Airport &airport, Plane &plane, file_data &fileData){

    Plane::passenger_in_plane * aux = plane.head_passenger;

    int _cap = plane.capacity/2;

    init_home_passengers(plane,fileData,_cap);

    int remaining_cap = plane.capacity - _cap;

    for (int i = 0; i < remaining_cap; ++i) {

        Nacionality * auxN = airport.nacionality_head;
        while (auxN->next_nacionality != NULL){
            if (auxN->root_passenger == NULL){
                auxN = auxN->next_nacionality;
                continue;
            }else{
                Plane::passenger_in_plane * passengerInPlane = plane.head_passenger;
                Plane::passenger_in_plane * passnode = new Plane::passenger_in_plane;
                while (passengerInPlane->next_passenger != nullptr) {
                    passengerInPlane = passengerInPlane->next_passenger;
                }
                passnode->passenger = auxN->root_passenger->passenger;
                passnode->next_passenger = nullptr;
                passengerInPlane->next_passenger = passnode;

                auxN->num_of_pass_in_tree = auxN->num_of_pass_in_tree == 0 ? 0:auxN->num_of_pass_in_tree-1;
                auxN->root_passenger = delete_node(auxN->root_passenger,auxN->root_passenger->passenger.first_name);
                auxN = auxN->next_nacionality;
                break;
            }
        }
        if (auxN->next_nacionality == NULL){
            init_passengers(plane,fileData,remaining_cap);
            break;
        }

    }
}

void add_ramp_plane(Airport &airport, file_data &fileData) {
    if (airport.head_arrv == NULL)return;

    // remove from arrival
    llnode * temp = airport.head_arrv;
    airport.head_arrv= airport.head_arrv->next;
    airport.num_in_arrival--;

    // add to ramp
    llnode * new_arrival_to_ramp = new llnode;
    new_arrival_to_ramp->plane = temp->plane;
    new_arrival_to_ramp->plane.head_passenger = nullptr;
    new_arrival_to_ramp->next = nullptr;

    if (airport.head_ramp == NULL){
        airport.head_ramp = new_arrival_to_ramp;

    }else {
        llnode * ptr = airport.head_ramp;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_arrival_to_ramp;
        airport.num_in_ramp++;
    }

    delete temp;
}

void log_passenger(passenger *passageiro) {
    std::cout << std::endl;
    std::cout << "Primeiro Nome: " << passageiro->first_name << std::endl;
    std::cout << "Segundo Nome: " << passageiro->second_name << std::endl;
    std::cout << "Nacionalidade: " << passageiro->nacionality << std::endl;
    std::cout << "Numero ticket: " << passageiro->ticket_num << std::endl;
}

void log_passengers_in_plane(Plane plane){
    // creates aux var to traverse linked list to not destroy it
    Plane::passenger_in_plane * passNode = plane.head_passenger;
    std::cout << "Passenger: ";
    if (!passNode) std::cout << "Plane Empty\n";
    while (passNode) {
        std::cout << passNode->passenger.first_name << ", ";
        passNode = passNode->next_passenger;
    }
    std::cout << std::endl;
}

void log_planes(llnode * list){

    if (list == nullptr){
        return;
    }else
        log_planes(list->next);


    std::cout << "\n";
    std::cout << "Plane: " << list->plane.flight_name << ",\n";
    std::cout << "Model: " << list->plane.model << ",\n";
    std::cout << "Origin: " << list->plane.origin << ",\n";
    std::cout << "Destination: " << list->plane.destination << "\n";
    log_passengers_in_plane(list->plane);
    std::cout << "\n--------------\n";

}

void reverse_ramp(Airport &airport) {

    // aux vars to reverse the links
    llnode * current_plane = airport.head_ramp;
    llnode * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;

    }

    // assign new head with links fixed to the actual head
    airport.head_ramp = prev_plane;

}



void remove_passengers(Airport &airport) {

    llnode * aux = new llnode;

    aux->plane.head_passenger = airport.head_arrv->plane.head_passenger;

    while (aux->plane.head_passenger != NULL) {

        aux->plane.head_passenger = aux->plane.head_passenger->next_passenger;

    }
    airport.head_arrv->plane.head_passenger = aux->plane.head_passenger;

}

void emergency_handler(Airport &airport,file_data &fileData) {

    bool valid = false;

    std::string plane_name;
    llnode * aux = airport.head_arrv;
    llnode * aux2;

    while(!valid) {

        std::cout << "Wich Plane is in emergency? (q)uit\n";
        std::cin >> plane_name;

        if (plane_name == "q")return;

        while (aux != NULL){
            if(plane_name == aux->plane.flight_name){
                valid = true;
                std::cout << "AAAA";
                break;
            }
            aux2 = aux;
            aux = aux->next;
            if(aux == NULL){
                std::cout << "Invalid option\n";
            }
        }
    }

    if(airport.ramp_cap >= 6 ) {
        add_departing_plane(airport, fileData); //remove plane from ramp to depart
    }

    aux2->next = aux->next; // aux ta livre
    aux->next = NULL;

    if (airport.head_ramp == NULL) airport.head_ramp = aux;

    llnode * temp = airport.head_ramp;

    while (temp != NULL){
        temp = temp->next;
    }

    temp = aux;

    //TODO need to add the emergency plane on the ramp and add a new plane on the arrivals

}

/*
 * Tree
 */

Nacionality::Pass_tree * new_tree_node(struct passenger &passenger) {

    Nacionality::Pass_tree * tree_node = new Nacionality::Pass_tree;

    tree_node->passenger = passenger;

    tree_node->left = NULL;
    tree_node->right = NULL;

    return tree_node;

}

Nacionality::Pass_tree * insert_tree_node(Nacionality::Pass_tree * tree_node, struct passenger &passenger) {

    // if root is null add passenger to the root
    if (tree_node == nullptr)return new_tree_node(passenger);

    // compare the name of the root and the next passenger
    int comparison_result = passenger.first_name.compare(tree_node->passenger.first_name);

    // gets comparision result and acts accordingly
    if (comparison_result < 0) {

        // add to the left if less than original
        tree_node->left =insert_tree_node(tree_node->left, passenger);;

    } else if (comparison_result > 0) {

        // add right if more than original
        tree_node->right = insert_tree_node(tree_node->right, passenger); ;
    }

    // returns the root again but modified
    return (tree_node);

}

Nacionality::Pass_tree * delete_node(Nacionality::Pass_tree * root, std::string name){

    if(root==NULL)return root;

    Nacionality::Pass_tree * aux = root;

    if (name < aux->passenger.first_name){

        aux->left = delete_node(aux->left,name);

        return aux;
    }

    if (name > aux->passenger.first_name){

        aux->right = delete_node(aux->right,name);

        return aux;
    }

    // If the current root is the node to be deleted
    if (aux->passenger.first_name == name) {
        // If the node has no children or only one child
        if (aux->left == nullptr) {
            Nacionality::Pass_tree *temp = aux->right;
            delete aux;
            return temp;
        } else if (aux->right == nullptr) {
            Nacionality::Pass_tree *temp = aux->left;
            delete aux;
            return temp;
        }

        // If the node has two children, find its inorder successor
        Nacionality::Pass_tree *parent_successor = aux;
        Nacionality::Pass_tree *successor = aux->right;
        while (successor->left != nullptr) {
            parent_successor = successor;
            successor = successor->left;
        }

        // Copy the successor's data to the current root
        aux->passenger = successor->passenger;

        // Delete the successor node from its original position
        if (parent_successor->left == successor) {
            parent_successor->left = successor->right;
        } else {
            parent_successor->right = successor->right;
        }
        delete successor;
    }

    return aux;

}
int make_spine(Nacionality::Pass_tree  * root){

    int count = 0;
    Nacionality::Pass_tree * temp = root->right;

    while (temp){

        if (temp->left){

            Nacionality::Pass_tree * OldTemp = temp;
            temp = temp->left;
            OldTemp->left = temp->right;
            temp->right = OldTemp;
            root->right = temp;
        }else{
            count++;
            root = temp;
            temp = temp->right;
        }

    }
    return count;
}

void compressTree(Nacionality::Pass_tree * root, int num_of_nodes){
    Nacionality::Pass_tree * temp = root->right;

    for (int i = 0; i < num_of_nodes; ++i) {
        Nacionality::Pass_tree * OldTemp = temp;
        temp = temp->right;
        root->right = temp;
        OldTemp->right = temp->left;
        temp->left = OldTemp;
        root = temp;
        temp = temp->right;
    }
}

Nacionality::Pass_tree * balance_tree(Nacionality::Pass_tree * root){

    Nacionality::Pass_tree * newRoot = new Nacionality::Pass_tree;
    newRoot->left = NULL;
    newRoot->right = NULL;

    newRoot->right = root;

    int numOfRot = make_spine(newRoot);

    int height = log2(numOfRot + 1);

    int num_nodes = pow(2,height) - 1;

    compressTree(newRoot,numOfRot - num_nodes);

    for ( num_nodes = num_nodes/2; num_nodes > 0 ; num_nodes /= 2) {
        compressTree(newRoot,num_nodes);
    }

    return newRoot->right;
}
Nacionality::Pass_tree * search_namesTree(Nacionality::Pass_tree * root,std::string name){
    if (root == NULL)return root;

    Nacionality::Pass_tree * temp;

    if (name == root->passenger.first_name){
        return root;
    }else if (name < root->passenger.first_name){
        temp = search_namesTree(root->left,name);
        return temp;
    }else if (name > root->passenger.first_name){
        temp = search_namesTree(root->right,name);
        return temp;
    }

    return temp;

}

// Function to print the binary tree structure recursively
void print_tree_leftrigt(Nacionality::Pass_tree* root, int level) {
    if (root == nullptr)
        return;

    print_tree_leftrigt(root->right, level + 1);
    std::cout << std::endl;
    for (int i = 0; i <level; ++i)
        std::cout << "   ";

    std::cout<< level << " " << root->passenger.first_name << std::endl;

    for (int i = 0; i < level; i++)
        std::cout << " ";

    print_tree_leftrigt(root->left, level + 1);
}

void listSort(std::string list[], int list_size) {
    for (int i = 0; i < (list_size - 1); i++) {
        int min = i; // sting.compare(string to compare to) = -1 0 1
        for (int j = i + 1; j < list_size; j++){
                if (list[j].compare(list[min]) < 0)
                    min = j;
        }
        if (min != i)
            swap(list[i], list[min]);
    }
}

void travessiaInfixa(Nacionality::Pass_tree *nacionality) {
    if (nacionality == nullptr) return;
    travessiaInfixa(nacionality->left);
    std::cout << "Passsageiro: " << nacionality->passenger.first_name << std::endl;
    travessiaInfixa(nacionality->right);
}

void arriving_foreigners(Airport &airport) {

    std::string home_nationality = "Portuguese";
    Nacionality * auxN;
    Plane::passenger_in_plane * passengerInPlane = airport.head_arrv->plane.head_passenger;

    while (passengerInPlane->next_passenger != NULL){

        if (passengerInPlane->passenger.nacionality == home_nationality) {
            passengerInPlane = passengerInPlane->next_passenger;
            break;
        }
        else{
            auxN = airport.nacionality_head;
            while (auxN->next_nacionality != NULL){
                if (passengerInPlane->passenger.nacionality == auxN->nacionality){
                    ++auxN->num_of_pass_in_tree;
                    auxN->root_passenger = insert_tree_node(auxN->root_passenger,passengerInPlane->passenger);
                    break;
                }
                auxN = auxN->next_nacionality;
            }
        }

        passengerInPlane = passengerInPlane->next_passenger;
    }
}

passenger * search_passengers(llnode *list) {
    // TODO need to show all passenger with the SAME NAME  =)
    if (list == NULL){
        std::cout << "list is empty \n";
        return nullptr;
    }
    llnode * aux = list;
    std::string passenger_name;
    std::cout << "What's the passengers first name?  ";
    std::cin >> passenger_name;

    while (aux->next != NULL){

        Plane::passenger_in_plane * aux_pass = aux->plane.head_passenger;

        while (aux_pass->next_passenger != NULL){
            if (aux_pass->passenger.first_name == passenger_name){

                std::cout << "Passenger found..\n" << aux_pass->passenger.first_name << " " << aux_pass->passenger.second_name << std::endl;

                return &aux_pass->passenger;
            }
            aux_pass = aux_pass->next_passenger;
        }

        aux=aux->next;
    }
    std::cout << "Passenger was not found.. \n";
    return nullptr;
}

void change_nacionality(std::string newNationality, Airport &airport) {
    int choice;
    // facam com que o ulilizador escolha
    while (true) {
        std::cout << "Search by arrival (1) or departure (2)\n";
        std::cin >> choice;
        if (choice == 1) {
            passenger *passengero = search_passengers(airport.head_arrv);
            if (passengero == nullptr)return;
            passengero->nacionality = newNationality;
            break;
        } else if (choice == 2) {
            passenger *passengero = search_passengers(airport.head_dep);
            if (passengero == nullptr)return;
            passengero->nacionality = newNationality;
            break;
        } else
            std::cout << "Chose a valid option\n";
    }
}
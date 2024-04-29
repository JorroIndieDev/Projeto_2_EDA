//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"
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

void add_ramp_plane(Airport &airport, file_data &fileData){
    if (airport.head_arrv == NULL)return;

    // remove from arrival
    llnode * temp = airport.head_arrv;
    airport.head_arrv= airport.head_arrv->next;
    airport.num_in_arrival--;

    // add to ramp
    llnode * new_arrival_to_ramp = new llnode;
    new_arrival_to_ramp->plane = temp->plane;
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

void log_departures_passengers(Airport &airport) {
    std::cout << "\n---------Departing passengers----------\n";
    if (!airport.head_dep) {
        std::cout << "\nNo planes in departure.\n";
        return;
    }

    // creates aux var to traverse linked list to not destroy it
    llnode * depart_ptr = airport.head_dep;

    while (depart_ptr != NULL) {
        std::cout << "Departing Plane: " << depart_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << depart_ptr->plane.model << ", ";
        std::cout << "Origin: " << depart_ptr->plane.origin << ", ";
        std::cout << "Destination: " << depart_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane * passNode = depart_ptr->plane.head_passenger;

        if (!passNode) std::cout << "Departure Plane Empty\n";

        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        depart_ptr = depart_ptr->next;

        std::cout << "\n|-------------------|\n";
    }
}

void log_ramp_passengers(Airport &airport) {
    std::cout << "\n----------Ramp passengers in Plane---------\n";
    if (!airport.head_ramp) {
        std::cout << "\nNo planes in ramp.\n";
        return;
    }

    // creates aux var to traverse linked list to not destroy it
    llnode * ramp_ptr = airport.head_ramp;

    while (ramp_ptr) {
        std::cout << "Ramp Plane: " << ramp_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << ramp_ptr->plane.model << ", ";
        std::cout << "Origin: " << ramp_ptr->plane.origin << ", ";
        std::cout << "Destination: " << ramp_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane *passNode = ramp_ptr->plane.head_passenger;

        if (!passNode) std::cout << "Ramp Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        ramp_ptr = ramp_ptr->next;

        std::cout << "\n-------------------\n";
    }
}

void log_arrivals_passengers(Airport &airport) {
    std::cout << "\n---------Ariving passengers----------\n";
    if (!airport.head_arrv) {
        std::cout << "\nNo planes arriving.\n";
        return;
    }

    // creates aux var to traverse linked list to not destroy it
    llnode * arr_ptr = airport.head_arrv;

    while (arr_ptr) {
        std::cout << "Ariving Plane: " << arr_ptr->plane.flight_name << "\n";
        std::cout << "Model: " << arr_ptr->plane.model << ", ";
        std::cout << "Origin: " << arr_ptr->plane.origin << ", ";
        std::cout << "Destination: " << arr_ptr->plane.destination << "\n";

        // creates aux var to traverse linked list to not destroy it
        Plane::passenger_in_plane * passNode = arr_ptr->plane.head_passenger;
        if (!passNode) std::cout << "Arrival Plane Empty\n";
        while (passNode) {
            std::cout << "Ticket Number: " << passNode->passenger.ticket_num << ", ";
            std::cout << "Name: " << passNode->passenger.first_name << " " << passNode->passenger.second_name << ", ";
            std::cout << "Nationality: " << passNode->passenger.nacionality << "\n";
            passNode = passNode->next_passenger;
        }

        arr_ptr = arr_ptr->next;

        std::cout << "\n-------------------\n";
    }
}

void log_ramp_planes(Airport &airport) {

    if (airport.head_ramp) {

        std::cout << "\nPlanes in Ramp:\n";

        // creates aux var to traverse linked list to not destroy it
        llnode * rampNode = airport.head_ramp;

        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes in the ramp.\n";
    }
}

void log_arrival_planes(Airport &airport) {

    if (airport.head_arrv) {

        std::cout << "\nPlanes ariving:\n";

        // creates aux var to traverse linked list to not destroy it
        llnode * rampNode = airport.head_arrv;

        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes ariving.\n";
    }
}

void log_departure_planes(Airport &airport) {

    if (airport.head_dep) {

        std::cout << "\nPlanes in departure:\n";

        // creates aux var to traverse linked list to not destroy it
        llnode *rampNode = airport.head_dep;

        while (rampNode) {
            std::cout << "Plane: " << rampNode->plane.flight_name << ", ";
            std::cout << "Model: " << rampNode->plane.model << ", ";
            std::cout << "Origin: " << rampNode->plane.origin << ", ";
            std::cout << "Destination: " << rampNode->plane.destination << "\n";
            rampNode = rampNode->next;
        }
    } else {
        std::cout << "\nNo planes on departure\n";
    }

}

void reverse_departing(Airport &airport) {

    // aux vars to reverse the links
    llnode * current_plane = airport.head_dep;
    llnode * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;

    }

    // assign new head with links fixed to the actual head
    airport.head_dep = prev_plane;

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

void reverse_arrival(Airport &airport) {

    // aux vars to reverse the links
    llnode * current_plane = airport.head_arrv;
    llnode * prev_plane = nullptr, * next_plane = nullptr;

    // loop to "swap()"
    while (current_plane != nullptr) {

        next_plane = current_plane->next;
        current_plane->next = prev_plane;

        prev_plane = current_plane;
        current_plane = next_plane;
    }

    // assign new head with links fixed to the actual head
    airport.head_arrv = prev_plane;

}

void remove_passengers(Airport &airport){

    llnode * aux = new llnode;

    aux->plane.head_passenger = airport.head_arrv->plane.head_passenger;

    while (aux->plane.head_passenger != NULL) {

        aux->plane.head_passenger = aux->plane.head_passenger->next_passenger;

    }
    airport.head_arrv->plane.head_passenger = aux->plane.head_passenger;

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

// Function to print the binary tree structure recursively
void print2DUtil(Nacionality::Pass_tree* root, int level) {
    if (root == nullptr)
        return;


    print2DUtil(root->right, level + 1);
    std::cout << std::endl;
    for (int i = 0; i <level; ++i)
        std::cout << "   ";

    std::cout<< level << " " << root->passenger.first_name << std::endl;

    // Print vertical branches
    for (int i = 0; i < level; i++)
        std::cout << " ";

    print2DUtil(root->left, level + 1);
}
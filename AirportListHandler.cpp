//
// Created by goliv on 4/17/2024.
//

#include "Headers/AirportListHandler.h"

void remove_departing_plane(Airport &airport) {
    if (airport.head_dep == NULL)return; // if head is NULL list is empty

    // since we parse  address we create a temp var to delete it afterward so that there is no memory leak
    Airport::Depart * temp = airport.head_dep;
    airport.head_dep = airport.head_dep->next;
    airport.num_in_depart--;

    // delete temp var
    delete temp;
}

void add_arriving_plane(Airport &airport, Plane &plane) {

    // create new Arrival node to add to list
    Airport::Arrival * new_arrv = new Airport::Arrival;
    new_arrv->plane = plane;
    new_arrv->next = nullptr;

    // if head NULL add at the head
    if (airport.head_arrv == NULL){
        airport.head_arrv = new_arrv;

    }else { // else add at the end
        Airport::Arrival * ptr = airport.head_arrv;
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
    Airport::Ramp * temp = airport.head_ramp;
    airport.head_ramp = airport.head_ramp->next;
    airport.num_in_ramp--;

    // change destination and origin
    temp->plane.destination = fileData.destino[random_range(0,fileData.destino_size-1)];
    temp->plane.origin = "AeroportoEDA";

    // add to depart
    Airport::Depart * new_depart = new Airport::Depart;
    new_depart->plane = temp->plane;
    new_depart->next = nullptr;

    if (airport.head_dep == NULL){
        airport.head_dep = new_depart;

    }else {
        Airport::Depart * ptr = airport.head_dep;
        while (ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = new_depart;
        airport.num_in_depart++;
    }

    delete temp;
}

void add_ramp_plane(Airport &airport, file_data &fileData) {
    if (airport.head_arrv == NULL)return;

    // remove from arrival
    Airport::Arrival * temp = airport.head_arrv;
    airport.head_arrv= airport.head_arrv->next;
    airport.num_in_arrival--;

    // add to ramp
    Airport::Ramp * new_arrival_to_ramp = new Airport::Ramp;
    new_arrival_to_ramp->plane = temp->plane;
    new_arrival_to_ramp->next = nullptr;

    if (airport.head_ramp == NULL){
        airport.head_ramp = new_arrival_to_ramp;

    }else {
        Airport::Ramp *ptr = airport.head_ramp;
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
    Airport::Depart * depart_ptr = airport.head_dep;

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
    Airport::Ramp * ramp_ptr = airport.head_ramp;

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
    Airport::Arrival * arr_ptr = airport.head_arrv;

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
        Airport::Ramp *rampNode = airport.head_ramp;

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
        Airport::Arrival *rampNode = airport.head_arrv;

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
        Airport::Depart *rampNode = airport.head_dep;

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


/*
 * NOTES:
 * h = height
 * lf = left
 * rt = right
 *      - tree balance factor = lf_h subTree - rt_h subTree = {-1,0,1}
 *      -
 * TODO CHANGE TREE TO DSW
 */

Nacionality::Pass_tree * new_tree_node(struct passenger &passenger) {

    Nacionality::Pass_tree * tree_node;

    tree_node->passenger = passenger;

    tree_node->left = NULL;
    tree_node->right = NULL;
    tree_node->height = 1;

    return tree_node;

}

Nacionality::Pass_tree * rotate_node_to_right(Nacionality::Pass_tree * tree_node) {

    Nacionality::Pass_tree * aux_node = tree_node->left;
    Nacionality::Pass_tree * temp_node = aux_node->right;

    // Rotation
    aux_node->right = tree_node;
    tree_node->left = temp_node;

    // update heights
    tree_node->height = max(node_height(tree_node->left),
                            node_height(tree_node->right)) + 1;

    tree_node->height = max(node_height(aux_node->left),
                            node_height(aux_node->right)) + 1;

    // return new root
    return aux_node;

}

Nacionality::Pass_tree * rotate_node_to_left(Nacionality::Pass_tree * tree_node) {

    Nacionality::Pass_tree * aux_node = tree_node->right;
    Nacionality::Pass_tree * temp_node = aux_node->left;

    // Rotation
    aux_node->left = tree_node;
    tree_node->right = temp_node;

    // update heights
    tree_node->height = max(node_height(tree_node->left),
                            node_height(tree_node->right)) + 1;

    aux_node->height = max(node_height(aux_node->left),
                           node_height(aux_node->right)) + 1;

    // return new root
    return aux_node;

}

Nacionality::Pass_tree * insert_tree_node(Nacionality::Pass_tree * tree_node, struct passenger &passenger) {

    /* 1.  Perform the normal BST rotation */
    // simple, if node is null just add the value in it
    if (tree_node == NULL)
        return (new_tree_node(passenger));

    // orderes by first name, TODO may need to check second name as well how? no clue
    if (passenger.first_name < tree_node->passenger.first_name)tree_node->left = insert_tree_node(tree_node->left, passenger);
    else tree_node->right = insert_tree_node(tree_node->right, passenger);

    /* 2. Update height of this ancestor node */
    // getting the height of the node by the max value between the left and right nodes
    tree_node->height = max(node_height(tree_node->left),
                            node_height(tree_node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
     this node became unbalanced */
    int balance = get_node_balance(tree_node);

    // 4 cases if node is not balanced

    // Left Left
    if (balance > 1 && passenger.first_name < tree_node->left->passenger.first_name)
        return rotate_node_to_right(tree_node);

    // Right Right
    if (balance < -1 && passenger.first_name > tree_node->right->passenger.first_name)
        return rotate_node_to_left(tree_node);

    // Left Right
    if (balance > 1 && passenger.first_name > tree_node->left->passenger.first_name) {
        tree_node->left = rotate_node_to_left(tree_node->left);
        return rotate_node_to_right(tree_node);
    }

    // Right Left
    if (balance < -1 && passenger.first_name < tree_node->right->passenger.first_name) {
        tree_node->right = rotate_node_to_right(tree_node->right);
        return rotate_node_to_left(tree_node);
    }

    // returns tree node
    return tree_node;

}

int get_node_balance(Nacionality::Pass_tree * tree_node){

    if (NULL == tree_node)return 0;

    // node is inbalanced if left-right heights != 1 || 0 || -1
    return node_height(tree_node->left) - node_height(tree_node->right);

}

int node_height(Nacionality::Pass_tree * tree_node) {

    // seperate function for ease of debug and use
    if (tree_node == NULL)return 0;

    // just return the height if the node is not null
    return tree_node->height;

}

void preOrder(Nacionality::Pass_tree * root) {

    if (NULL != root) {

        std::cout << root->passenger.first_name << std::endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}
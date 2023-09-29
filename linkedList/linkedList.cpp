#include "linkedList.h"

// Define the Node class to represent individual elements in the list.
Node::Node(int value) : data(value), next(nullptr) {};

// Define the List class to manage the linked list.
List::List() : head(nullptr){};

void List::append(int value){
    // Create a new node with the given value.
    Node* newNode = new Node(value);
    // Make the new node point to the current head.
    newNode->next = head;
    // Update the head to the new node.
    head = newNode;
}

// Function to display the elements in the list.
void List::display() {

    Node* current = head;  // Start from the head of the list.
    
    while (current) {     // Loop until the end of the list (nullptr).
        std::cout << current->data << " -> ";  // Print the current node's data.
        current = current->next;  // Move to the next node.
    }

    std::cout << "Null pointer reached." << std::endl;
}

/*
// Naive copy constructor (incorrect).
List::List(const List& copy) {
    head = copy.head; // Copy the pointer to the head node.
}
*/

List::List(const List& copy) {

    head = nullptr; // Inititalize the new linked list as empty.

    // Traverse the nodes of the given list.
    Node* copyCurrent = copy.head;
    while (copyCurrent) {
        // Create a new node with the same data.
        append(copyCurrent->data);
        // Set the current pointer to the next pointer in the list.
        copyCurrent = copyCurrent->next;
    }
}

// TODO: Currently, this makes a copy in the reverse order.
// Overloaded assignment operator for deep copying.
List& List::operator=(const List& copy) {
    // Check for self assignment to prevent redundant work.   
    if (this == &copy){
        return *this;
    }

    // Clear the existing list
    while (head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Copy the elements from the given list by traversing across the nodes.
    Node* copyCurrent = copy.head;
    while (copyCurrent){
        // Create new nodes with the same data.
        List::append(copyCurrent->data);
        copyCurrent = copyCurrent->next;
    }

    // Return a reference to the current list.
    return *this;

};


// Destructor to free memory when the list is destroyed.
List::~List() {

    while (head) {          // While there are nodes in the list.
        Node* temp = head;  // Store the current head in a temporary pointer.
        head = head->next;  // Move the head to the next node.
        delete temp;        // Delete the previous head.
    }

}

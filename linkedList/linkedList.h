#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

// Define the Node class to represent individual elements in the list.
class Node {
    
    public:

        int data;     // Data stored in the node.
        Node* next;   // Pointer to the next node in the list.

        // Constructor to initialize a node with data and set next to nullptr.
        Node(int value);

};

// Define the List class to manage the linked list.
class List {

    private:

        Node* head;  // Pointer to the first node in the list.

    public:   
        
        List();

        // Function to add an element to the front of the list.
        void append(int value);

        // Function to display the elements in the list.
        void display();

        /*
        // Naive copy constructor (incorrect).
        List(const List& copy) {
            head = copy.head; // Copy the pointer to the head node.
        }
        */

        List(const List& copy);

        // TODO: Currently, this makes a copy in the reverse order.
        // Overloaded assignment operator for deep copying.
        List& operator=(const List& copy);


        // Destructor to free memory when the list is destroyed.
        ~List();

};

#endif
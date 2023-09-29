/*

    Define a class named “List”, which represents a linked list, and test the class. (10 marks)
    Write a test program to create a copy of a list. Call the default assignment for the objects in the List class. Note how your program reacts. (20 marks)
    A trial run of the program shows that the class is incomplete. Since the class contains dynamic members, the following tasks must be performed:
        Define a copy constructor for the List class. (10 marks)
        Overload the assignment operator. (10 marks)


*/

#include <iostream>

// Define the Node class to represent individual elements in the list.
class Node {
    public:
        int data;     // Data stored in the node.
        Node* next;   // Pointer to the next node in the list.

        // Constructor to initialize a node with data and set next to nullptr.
        Node(int value) : data(value), next(nullptr) {}

};

// Define the List class to manage the linked list.
class List {

    private:   
        Node* head;  // Pointer to the first node in the list.

    public:   
        // Constructor to initialize an empty list.
        List() : head(nullptr) {}

        // Function to add an element to the front of the list.
        void append(int value) {
            // Create a new node with the given value.
            Node* newNode = new Node(value);
            // Make the new node point to the current head.
            newNode->next = head;
            // Update the head to the new node.
            head = newNode;
        }

        // Function to display the elements in the list.
        void display() {

            Node* current = head;  // Start from the head of the list.
            
            while (current) {     // Loop until the end of the list (nullptr).
                std::cout << current->data << " -> ";  // Print the current node's data.
                current = current->next;  // Move to the next node.
            }

            std::cout << "Null pointer reached." << std::endl;
        }


        // Destructor to free memory when the list is destroyed.
        ~List() {

            while (head) {          // While there are nodes in the list.
                Node* temp = head;  // Store the current head in a temporary pointer.
                head = head->next;  // Move the head to the next node.
                delete temp;        // Delete the previous head.
            }

        }
};

int main() {

    List test;          // Create an empty list.

    test.append(3);  // Add elements to the front of the list.
    test.append(2);
    test.append(1);

    std::cout << "List: ";
    test.display();     // Display the list.

    return 0;
}
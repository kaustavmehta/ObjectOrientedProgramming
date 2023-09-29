#include "linkedList.h"

int main() {

    List test;          // Create an empty list.

    test.append(3);  // Add elements to the front of the list.
    test.append(2);
    test.append(1);

    std::cout << "Original List: ";
    test.display();     // Display the list.

    //List copyList(test); // Using the naive and incorrect copy constructor

    List copiedList;
    copiedList = test; // Use overloaded assignment operator to implicitly make a deep copy. 

    std::cout << "Copied List: ";
    copiedList.display();

    return 0;
}
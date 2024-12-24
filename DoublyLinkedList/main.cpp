#include <iostream>
using namespace std;

// Structure representing a doubly linked list node
struct Dnode {
    Dnode* prev; // Pointer to the previous node
    Dnode* next; // Pointer to the next node
    int key;     // Data stored in the node
};

// Helper function to insert a new node before a reference node
// Parameters:
// - referenceNode: The node before which the new node will be inserted
// - newValue: The value to store in the new node
void insertNode(Dnode* referenceNode, const int newValue);

// Adds a new node to the front of the list
// Parameters:
// - header: Reference to the pointer to the header node
// - key: Value to store in the new node
void addFront(Dnode* &header, const int key);

// Adds a new node to the back of the list
// Parameters:
// - trailer: Reference to the pointer to the trailer node
// - key: Value to store in the new node
void addback(Dnode* &trailer, const int key);

// Prints the list in forward order starting from the header node
// Parameters:
// - header: Pointer to the header node
void printForward(Dnode* header);

// Prints the list in reverse order starting from the trailer node
// Parameters:
// - trailer: Pointer to the trailer node
void PrintBackward(Dnode* trailer);

int main() {
    // Creating header and trailer sentinel nodes
    Dnode* header = new Dnode();
    Dnode* trailer = new Dnode();

    // Initialize header and trailer with sentinel values
    header->key = trailer->key = 9999; // Sentinel value indicating non-data nodes
    header->next = trailer;           // Link header to trailer
    trailer->prev = header;           // Link trailer to header

    // Add nodes to the front of the list (0 to 5)
    for (int i = 0; i <= 5; i++) {
        addFront(header, i);
    }

    // Print the list in forward order
    cout << "List after adding to the front:" << endl;
    printForward(header);

    // Add nodes to the back of the list (-1 to -5)
    for (int i = -1; i >= -5; i--) {
        addback(trailer, i);
    }

    // Print the list in forward order again
    cout << "List after adding to the back:" << endl;
    printForward(header);

    // Print the list in reverse order
    cout << "Printing backward: \n";
    PrintBackward(trailer);

    return 0;
}

void insertNode(Dnode* referenceNode, const int newValue) {
    // Create a new node with the given value
    Dnode* newNode = new Dnode();
    newNode->key = newValue;

    // Link the new node into the list
    newNode->next = referenceNode;               // Point newNode's next to referenceNode
    newNode->prev = referenceNode->prev;         // Point newNode's prev to referenceNode's prev
    referenceNode->prev->next = newNode;         // Update previous node's next to newNode
    referenceNode->prev = newNode;               // Update referenceNode's prev to newNode
}

void addFront(Dnode* &header, const int key) {
    // Insert a new node immediately after the header (before the first valid node)
    insertNode(header->next, key);
}

void addback(Dnode* &trailer, const int key) {
    // Insert a new node immediately before the trailer
    insertNode(trailer, key);
}

void printForward(Dnode* header) {
    // Start traversal from the first valid node (header->next)
    Dnode* temp = header->next;

    // Traverse until the trailer node is reached
    while (temp != nullptr && temp->key != 9999) {
        cout << temp->key; // Print the current node's key

        // Print separator if the next node is valid and not the trailer
        if (temp->next != nullptr && temp->next->key != 9999) {
            cout << " <--> ";
        }

        temp = temp->next; // Move to the next node
    }

    cout << endl; // Print a newline at the end
}

void PrintBackward(Dnode* trailer) {
    // Start traversal from the trailer node
    Dnode* temp = trailer;

    // Traverse until the header node is reached
    while (temp->prev->prev != nullptr) {
        cout << temp->prev->key; // Print the current node's key

        // Print separator if more nodes exist in reverse
        if (temp->prev->prev != nullptr) {
            cout << " <--> ";
        }

        temp = temp->prev; // Move to the previous node
    }

    cout << endl; // Print a newline at the end
}

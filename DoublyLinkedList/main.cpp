#include <iostream>
using namespace std;

struct Dnode {
    Dnode* prev;
    Dnode* next;
    int key;
};

// Helper function to insert a new node before the reference node
void insertNode(Dnode* referenceNode, const int newValue);
// Add a new node to the front of the list
void addFront(Dnode* &header, const int key);
// Add a new node to the back of the list
void addback(Dnode* &trailer, const int key);
// Print the list forward starting from the header
void printForward(Dnode* header);
//Print the list Backward starting from the trailer
void  PrintBackward(Dnode* trailer);



int main() {
    // Creating header and trailer pointers
    Dnode* header = new Dnode();
    Dnode* trailer = new Dnode();

    // Initialize header and trailer
    header->key = trailer->key = 9999; // Sentinel values
    header->next = trailer;
    trailer->prev = header;

    // Add nodes to the front of the list
    for (int i = 0; i <= 5; i++) {
        addFront(header, i);
    }

    // Print the list forward
    cout << "List after adding to the front:" << endl;
    printForward(header);

    // Add nodes to the back of the list
    for (int i = -1; i >= -5; i--) {
        addback(trailer, i);
    }

    // Print the list forward again
    cout << "List after adding to the back:" << endl;
    printForward(header);
    //Print the list backward:
    cout << "Printing backward: \n";
    PrintBackward(trailer);

    return 0;
}

void insertNode(Dnode* referenceNode, const int newValue) {
    // Step 1: Create a new node
    Dnode* newNode = new Dnode();
    newNode->key = newValue;

    // Step 2: Link the new node into the list
    newNode->next = referenceNode;
    newNode->prev = referenceNode->prev;
    referenceNode->prev->next = newNode;
    referenceNode->prev = newNode;
}

void addFront(Dnode* &header, const int key) {
    // Insert a node after the header (before the first valid node)
    insertNode(header->next, key);
}

void addback(Dnode* &trailer, const int key) {
    // Insert a node before the trailer
    insertNode(trailer, key);
}

void printForward(Dnode* header) {
    // Start from the first valid node (header->next)
    Dnode* temp = header->next;

    // Traverse until the trailer node (temp->key == 9999)
    while (temp != nullptr && temp->key != 9999) {
        cout << temp->key;

        // Add separator if there is a next valid node
        if (temp->next != nullptr && temp->next->key != 9999) {
            cout << " <--> ";
        }

        // Move to the next node
        temp = temp->next;
    }

    cout << endl; // Print a new line at the end
}

void  PrintBackward(Dnode* trailer){
    Dnode* temp = trailer;

    while(temp->prev->prev != nullptr){
        cout << temp->prev->key << " <--> ";
        temp = temp->prev;
    }
    cout << endl;
    

}

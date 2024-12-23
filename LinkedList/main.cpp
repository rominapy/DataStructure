#include <iostream>
using namespace std;

// ================================================================
// Definition of a Node structure for a linked list.
// Each node contains an integer key and a pointer to the next node.
// ================================================================
struct Node {
    int key;        // Value stored in the node
    Node* next;     // Pointer to the next node in the list
};

// ================================================================
// Function prototypes for linked list operations
// ================================================================
void print(Node* head);                // Prints the linked list
void pushFront(int key, Node*& head);  // Adds a node to the front of the list
void pushBack(int key, Node*& head);   // Adds a node to the back of the list
void popFront(Node*& head);            // Removes a node from the front of the list
void popBack(Node*& head);             // Removes a node from the back of the list

int main() {
    // ================================================================
    // Initializing the head pointer to represent an empty list
    // ================================================================
    Node* head = nullptr;

    // ================================================================
    // Adding numbers (10, 9, 8, ...) to the front of the linked list
    // ================================================================
    for (int i = 1; i <= 10; i++) {
        pushFront(i, head);
    }

    // Printing the linked list after pushing numbers to the front
    cout << "Printing the numbers that we pushed to the front:\n";
    print(head);

    // ================================================================
    // Adding numbers (1, 0, -1, -2, ...) to the back of the linked list
    // ================================================================
    for (int i = 0; i >= -5; i--) {
        pushBack(i, head);
    }

    // Printing the linked list after pushing numbers to the back
    cout << "Printing the numbers that we pushed to the back:\n";
    print(head);

    // ================================================================
    // Removing the first element from the front of the list
    // ================================================================
    popFront(head);
    cout << "Removing the first element from the front:\n";
    print(head);

    // ================================================================
    // Adding the element 10 back to the front of the list
    // ================================================================
    cout << "Adding back the first element to the front:\n";
    pushFront(10, head);
    print(head);

    // ================================================================
    // Removing the last element from the back of the list
    // ================================================================
    cout << "Removing from the back of the list:\n";
    popBack(head);
    print(head);

    return 0;
}

// ================================================================
// Prints the elements of the linked list in order
// ================================================================
void print(Node* head) {
    while (head != nullptr) {
        cout << head->key << " ---> ";
        head = head->next;
    }
    cout << "NULL\n"; // Indicates the end of the list
}

// ================================================================
// Adds a new node with the given key to the front of the list
// ================================================================
void pushFront(int key, Node*& head) {
    Node* newNode = new Node(); // Create a new node
    newNode->key = key;         // Assign the key value
    newNode->next = head;       // Point the new node to the current head
    head = newNode;             // Update head to the new node
}

// ================================================================
// Adds a new node with the given key to the back of the list
// ================================================================
void pushBack(int key, Node*& head) {
    Node* newNode = new Node(); // Create a new node
    newNode->key = key;         // Assign the key value
    newNode->next = nullptr;    // New node will point to null as it will be the last node

    // If the list is empty, set the new node as the head
    if (head == nullptr) {
        head = newNode;
    } else {
        // Traverse the list to find the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to the new node
    }
}

// ================================================================
// Removes the first node of the list
// ================================================================
void popFront(Node*& head) {
    if (head == nullptr) {
        // If the list is empty, there is nothing to remove
        return;
    } else {
        Node* temp = head;    // Temporarily store the current head
        head = temp->next;    // Update the head to the next node
        delete temp;          // Free the memory of the removed node
    }
}

// ================================================================
// Removes the last node of the list
// ================================================================
void popBack(Node*& head) {
    if (head == nullptr) {
        // If the list is empty, there is nothing to remove
        return;
    }

    if (head->next == nullptr) {
        // If the list has only one node, delete it and set head to null
        delete head;
        head = nullptr;
        return;
    }

    // Traverse the list to find the second-to-last node
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // Delete the last node and update the second-to-last node's next pointer
    delete temp->next;
    temp->next = nullptr;
}

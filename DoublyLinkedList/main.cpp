#include <iostream>
using namespace std;


 struct Dnode{
    Dnode* prev;
    Dnode* next;
    int key;
   
 };

// helper function to use in addfront and addback
void insertNode(Dnode* referenceNode, const int newValue); // insert a new node before v
 // void remove(Dnode* v);//remove node v
void addFront(Dnode* &header,const int key);
void addback(Dnode* &trailer, const int key);


void printForward(Dnode* header);

int main(){


    // creating header and trailer pointers 
    Dnode* header= new Dnode();
    Dnode* trailer = new Dnode();

    //having them point to each other
    header->next = trailer;
    trailer->prev= header;



    for ( int i=0; i<=5; i++){
        addFront(header, i);
    }

    printForward(header);







    return 0;
}

void insertNode(Dnode* referenceNode, const int newValue) {
    // Step 1: Create a new node
    Dnode* newNode = new Dnode(); // Allocate memory for the new node
    newNode->key = newValue;      // Assign the value to the new node

    // Step 2: Link the new node to the reference node and its neighbors
    newNode->next = referenceNode;              // Point the new node's next to the reference node
    newNode->prev = referenceNode->prev;        // Point the new node's prev to the reference node's previous node

    // Step 3: Update pointers of surrounding nodes to include the new node
    referenceNode->prev->next = newNode;        // Update the previous node's next to point to the new node
    referenceNode->prev = newNode;              // Update the reference node's prev to point to the new node
}

void addFront(Dnode* &header,const int key){
      insertNode(header->next,key);
}

void addback(Dnode* &trailer, const int key){
    insertNode(trailer,key);
}
void printForward(Dnode* header){

    Dnode* temp = header;
    while(temp != nullptr){
        cout << temp->key << " <--> " ;
        temp = temp->next;
    }
    cout << endl;
}


#include <iostream>
using namespace std;

// The node that we are using for the linked list, consisting of one key and a pointer to the next node
struct Node{
    int key;
    Node* next;
};

void print(Node* head);
void pushFront(int key, Node* &head);

int main(){

    //Initializing the head pointer
     Node* head = nullptr;
    
    //Pushing numbers to the front of the linked list( 10,9,8,..)
    for( int i=1; i<= 10; i++)
    { 
        pushFront(i,head);
    }
    // printing the keys
    print(head);


    //Pushing numbers to the back of the linked list(1,0,-1,-2,...)
   


    return 0;
}

void print(Node* head){
    while(head != nullptr){
        cout << head->key <<" --->" ;
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}

void pushFront(int key, Node* &head){
    Node* newNode = new Node();
    newNode->key = key;
    newNode->next = head;
    head = newNode;
}

void pushBack(int key, Node* &head){

    
}
#include <iostream>
using namespace std;

// The node that we are using for the linked list, consisting of one key and a pointer to the next node
struct Node{
    int key;
    Node* next;
};

void print(Node* head);
void pushFront(int key, Node* &head);
void pushBack(int key, Node* &head);
void popFront(Node*& head);

int main(){

    //Initializing the head pointer
     Node* head = nullptr;
    
    //Pushing numbers to the front of the linked list( 10,9,8,..)
    for( int i=1; i<= 10; i++)
    { 
        pushFront(i,head);
    }
    // printing the keys
    cout<< "Printing the numbers that we pushed to the fronte: \n";
    print(head);


    //Pushing numbers to the back of the linked list(1,0,-1,-2,...)
    for(int i=0; i>=-5; i--){

        pushBack(i,head);
    }

    // printing the keys
    cout<< "Printing the numbers that we pushed to the back: \n";
    print(head);

    //calling the pop front function to delete 10 from the front
    popFront(head);

    // 
    cout <<"Removing the first element from the front: \n";
    print(head);

    cout <<"Adding back the first element to the front: \n";
    pushFront(10,head);
    print(head);

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
  

    Node* newNode = new Node();
    newNode->key = key;
    newNode->next = nullptr;
  // handling empty list

    if(head == nullptr){
        head = newNode;
     }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next= newNode;

    }
}

void popFront(Node*& head){
    if(head->next== nullptr){
        //in order to delr
      head = nullptr;  

    }
    else{
        Node* temp = head ;
        head = temp->next;
        delete temp;

    }

}